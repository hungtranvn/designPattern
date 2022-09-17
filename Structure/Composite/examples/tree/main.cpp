#include "component.h"
#include "composite.h"
#include "leaf.h"
#include <iostream>

void clientCode (Component* component) {
  std::cout << "RESULT: " << component->operation() << "\n\n";
}

int main() {
  Component* tree = new Composite;
  
  Component* branch1 = new Composite;
  
  Component* leaf1 = new Leaf;
  Component* leaf2 = new Leaf;
  Component* leaf3 = new Leaf;
  
  branch1->add(leaf1);
  branch1->add(leaf2);
  branch1->add(leaf3);

  Component* branch2 = new Composite;

  Component* leaf4 = new Leaf;

  branch2->add(leaf4);
  
  Component* leaf5 = new Leaf;

  tree->add(branch1);
  tree->add(branch2);
  tree->add(leaf5);

  std::cout << "dont need to check the classes when managing tree: \n";
  clientCode(tree);

  delete tree;
  delete branch1;
  delete branch2;

  delete leaf1;
  delete leaf2;
  delete leaf3;
  delete leaf4;
  delete leaf5;
  
  return 0;
}
