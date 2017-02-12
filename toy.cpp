#include <iostream>
#include <string>
#include <stdexcept>
#include "node.h"
#include "tokens.h"
#include "heap.h"

const std::string numbers ("1234567890");

bool is_number(char ch){
  return numbers.find(ch) != std::string::npos;
}

tokens tokenize(std::string input){
  int len = input.length();
  int counter = 0;

  tokens token_list(len);

  while(counter < len){
    std::string current ("");
    if(is_number(input.at(counter))){
      while(is_number(input.at(counter))){
        current += input.at(counter);
        counter++;
      }
      token tok('i', current);
      token_list.insert(tok);
    } else if(input.at(counter) == '('){
      token tok('o');
      token_list.insert(tok);
      counter++;
    } else if(input.at(counter) == ')'){
      token tok('c');
      token_list.insert(tok);
      counter++;
    } else if(input.at(counter) == '+'){
      token tok('a');
      token_list.insert(tok);
      counter++;
    } else if(input.at(counter) == '-'){
      token tok('s');
      token_list.insert(tok);
      counter++;
    } else if(input.at(counter) == '*'){
      token tok('m');
      token_list.insert(tok);
      counter++;
    } else {
      counter++;
    }
  }
  return token_list;
}

void parse(tokens * token_list, heap * main_heap){
  bool in_root = false;
  node * current_node;
  while(!token_list->finished()){
    token tok = token_list->next();
    if(tok.type == 'o'){
      /* open parens, make root node or descend to next function */
      if(!in_root){
        current_node = main_heap->get_node();
        current_node->init('f', new node());
        in_root = true;
      } else {
        node * parent = current_node;
        current_node = current_node->get_next_child();
        current_node->init('f', parent);
      }
    } else if(tok.type == 'c'){
      /* close parens, exit root node or ascend to previous function */
      if(current_node->parent->type == 'n'){
        in_root = false;
      } else {
        current_node = current_node->parent;
      }
    } else if(tok.type == 'i') {
      node * parent = current_node;
      current_node = current_node->get_next_child();
      current_node->init('v', parent);
      current_node->content = tok.content;
      current_node = current_node->parent;
    } else if(tok.type == 'a' || tok.type == 's' || tok.type == 'm'){
      current_node->content += tok.type;
    }
  }
}

int execute(node * root){
  if(root->type == 'v'){
    return std::stoi(root->content, nullptr, 10);
  } else if(root->get_func_type() == '+'){
    return execute(root->left) + execute(root->right);
  } else if(root->get_func_type() == '-'){
    return execute(root->left) - execute(root->right);
  } else if(root->get_func_type() == '*'){
    return execute(root->left) * execute(root->right);
  } else {
    throw std::logic_error("unknown node type");
  }
}

int main(){
  /* initialize heap */
  heap main_heap;
  /* test program */
  std::string program("(3 + (4 * 8))");
  /* tokenize program */
  tokens token_list = tokenize(program);
  /* parse program */
  parse(&token_list, &main_heap);
  /* execute program */
  for(int i = 0; i < main_heap.last_index(); i++){
    int result = execute(main_heap.node_at(i));
    std::cout << ">> " << result << "\n";
  }
}
