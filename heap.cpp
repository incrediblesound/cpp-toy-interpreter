#include "heap.h"

heap::heap(){
  this->nodes = new node[1000];
  this->length = 1000;
  this->current = 0;
}

node * heap::get_node(){
  this->current++;
  return &this->nodes[this->current-1];
}

node * heap::node_at(int i){
  return &this->nodes[i];
}

int heap::last_index(){
  return this->current;
}
