#ifndef POLAR_CREATOR_H
#define POLAR_CREATOR_H
#include "Creator.h"
class PolarCreator : public Creator {
public:
  Point* create() override;
};
#endif
