#ifndef ACTOR_H
#define ACTOR_H
class Actor {
	bool m_IsVisible{true};
public:
	void SetVisibility(bool visible) {
		m_IsVisible = visible;
	}
	bool IsVisible()const {
		return m_IsVisible;
	}
	virtual void Update() = 0;
	virtual ~Actor()=default;
};
#endif
