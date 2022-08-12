#ifndef RD70_DISPATCHER
#define RD70_DISPATCHER

#include <list>
#include <algorithm>

namespace ilrd
{

template <typename EVENT>
class Dispatcher;

template <typename EVENT>
class CallbackBase
{
public:
    CallbackBase() = default;
    virtual ~CallbackBase();

    CallbackBase(const CallbackBase &) = delete;
    CallbackBase &operator=(const CallbackBase &) = delete;

    virtual void Notify(EVENT event) = 0;
    virtual void NotifyDeath() = 0;

private:
    friend class Dispatcher<EVENT>;
    Dispatcher<EVENT> *m_dispatcher;
};

template <typename EVENT, typename OBSERVER>
class Callback : public CallbackBase<EVENT>
{
public:
    Callback(OBSERVER *,
             void (OBSERVER::*notifyMethod)(EVENT),
             void (OBSERVER::*notifyDeath)());
    virtual ~Callback(){}

    Callback(const Callback &) = default;
    Callback &operator=(const Callback &) = default;

    virtual void Notify(EVENT event);
    virtual void NotifyDeath();

private:
    OBSERVER *m_observer;
    void (OBSERVER::*m_notifyMethod)(EVENT);
    void (OBSERVER::*m_notifyDeath)();
};

template <typename EVENT>
class Dispatcher
{
public:
    Dispatcher() = default;
    ~Dispatcher();

    Dispatcher(const Dispatcher &) = delete;
    Dispatcher &operator=(const Dispatcher &) = delete;

    void NotifyAll(EVENT);
    void Register(CallbackBase<EVENT> *);
    void Unregister(CallbackBase<EVENT> *);

private:
    std::list<CallbackBase<EVENT> *> m_subscribers;
};

//_________________________________ Dispatcher _________________________________

template <typename EVENT>
Dispatcher<EVENT>::~Dispatcher()
{
    for_each(m_subscribers.begin(), m_subscribers.end(),
             [&](CallbackBase<EVENT> *callbackBase) {
                 callbackBase->NotifyDeath();
             });
}

template <typename EVENT>
void Dispatcher<EVENT>::NotifyAll(EVENT event)
{
    for_each(m_subscribers.begin(), m_subscribers.end(),
             [&](CallbackBase<EVENT> *callbackBase) {
                 callbackBase->Notify(event);
             });
}

template <typename EVENT>
void Dispatcher<EVENT>::Register(CallbackBase<EVENT> *callbackBase)
{
    callbackBase->m_dispatcher = this;
    m_subscribers.push_back(callbackBase);
}

template <typename EVENT>
void Dispatcher<EVENT>::Unregister(CallbackBase<EVENT> *callbackBase)
{
    callbackBase->m_dispatcher = nullptr;
    m_subscribers.remove(callbackBase);
}

//_____________________________ CallbackBase Class _____________________________

template <typename EVENT>
CallbackBase<EVENT>::~CallbackBase()
{
    if (nullptr != m_dispatcher)
    {
        m_dispatcher->Unregister(this);
    }
}

//_______________________________ Callback Class _______________________________

template <typename EVENT, typename OBSERVER>
Callback<EVENT, OBSERVER>::Callback(OBSERVER *observer,
                                    void (OBSERVER::*notifyMethod)(EVENT),
                                    void (OBSERVER::*notifyDeath)())
    : m_observer(observer), m_notifyMethod(notifyMethod), m_notifyDeath(notifyDeath)
{
}


template <typename EVENT, typename OBSERVER>
void Callback<EVENT, OBSERVER>::Notify(EVENT event)
{
    (m_observer->*m_notifyMethod)(event);
}


template <typename EVENT, typename OBSERVER>
void Callback<EVENT, OBSERVER>::NotifyDeath()
{
    (m_observer->*m_notifyDeath)();
}

} // namespace ilrd

#endif // RD70_DISPATCHER