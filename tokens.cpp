#include "tokens.h"
#include <stdexcept>

tokens::tokens(int size){
  this->length = 0;
  this->current = 0;
  this->list = new token[size];
}

token tokens::tokenAt(int location){
  if(location < 0 || location > this->length){
    throw std::invalid_argument( "location out of range" );
  }
  return this->list[location];
}

void tokens::insert(token tok){
  this->list[this->length] = tok;
  this->length++;
}

token tokens::next(){
  int current = this->current;
  this->current++;
  return this->list[current];
}

bool tokens::finished(){
  return this->current >= this->length;
}
