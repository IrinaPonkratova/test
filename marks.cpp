#pragma once
#include <string>
using namespace std;
struct Marks {
  int value;
  int count;

  Marks() {}
  Marks(int v, int c) 
: value(v),  
count(c) {}
  ~Marks() {}

};