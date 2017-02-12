#ifndef TOKENS_H_
#define TOKENS_H_

#include <string>

struct token {
  char type;
  std::string content;
  token(){}
  token(char t, std::string c) : type(t), content(c){}
  token(char t) : type(t){}
};

class tokens {
private:
  int length;
  int current;
public:
  tokens(int);
  token * list;
  void insert(token);
  token tokenAt(int);
  token next();
  bool finished();
};

#endif
