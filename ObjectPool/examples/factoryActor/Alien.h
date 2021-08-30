#ifndef ALIEN_H
#define ALIEN_H
#include "Actor.h"
class Alien : public Actor {
public:
	Alien();
	~Alien();
	void Update() override;
};
#endif
