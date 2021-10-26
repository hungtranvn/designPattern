#ifndef CARTESIAN_CREATOR_H
#define CARTESIAN_CREATOR_H
#include "Creator.h"
class CartesianCreator : public Creator {
public:
  Point* create() override;
};
#endif
