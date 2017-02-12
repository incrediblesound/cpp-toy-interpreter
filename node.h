#ifndef NODE_H_
#define NODE_H_

#include <string>

struct node {
    bool marked;
    char type;
    std::string content;
    node * left;
    node * right;
    node * parent;
    node();
    void init(char, node *);
    void print();
    char get_func_type();
    node * get_next_child();
};

#endif
