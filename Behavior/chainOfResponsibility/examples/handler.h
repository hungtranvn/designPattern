#ifndef _HANDLER_H_
#define _HANDLER_H_
class Handler {
private:
  Handler* successor;
public:
  virtual ~Handler() = default;
  virtual void setNextHandler(Handler* s);
  virtual void handlerRequest();
};
#endif // _HANDLER_H_
