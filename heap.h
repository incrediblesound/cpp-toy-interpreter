#ifndef HEAP_H_
#define HEAP_H_

#include "node.h"

class heap {
private:
  node * nodes;
  int length;
  int current;
public:
  heap();
  node * get_node();
  int last_index();
  node * node_at(int);
};

#endif
