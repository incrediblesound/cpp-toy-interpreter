#include "node.h"
#include <string>
#include <iostream>
#include <stdexcept>

node::node(){
  this->type = 'n';
  this->content = std::string("");
}

void node::init(char t, node * parent){
  this->type = t;
  this->left = new node();
  this->right = new node();
  this->parent = parent;
}

node * node::get_next_child(){
  if(this->left->type == 'n'){
    return this->left;
  } else if(this->right->type == 'n'){
    return this->right;
  } else {
    throw std::logic_error( "function has three arguments" );
  }
}

char node::get_func_type(){
  switch(this->content.at(0)){
    case 'a':
      return '+';
    case 's':
      return '-';
    case 'm':
      return '*';
  }
  throw std::logic_error("node has invalid function type");
}

void node::print(){
  if(this->type == 'n'){
    std::cout << "(n)";
  } else if(this->type == 'v'){
    std::cout << this->content;
  } else if(this->type == 'f'){
    std::cout << "(";
    this->left->print();
    std::cout << " " << this->get_func_type() << " ";
    this->right->print();
    std::cout << ")";
  } else {
    std::cout << "?";
  }
}
