#ifndef _TREE_H_
#define _TREE_H_
#include "treeModel.h"
class Tree {
private:
  TreeModel* model_;
  Vector position_;
  double height_;
  double thickness_;
  Color barkTint_;
  Color leafTint_;
}
#endif // _TREE_H_
