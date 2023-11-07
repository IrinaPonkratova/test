#pragma once
#include <string>
using namespace std;
struct Reading {
  string type;
  int weight;
  string direction;
  double coast;

  Reading() {}
  Reading(string t, int w, string d, double c) 
: type(t), 
weight(w), 
direction(d), 
coast(c) {}
  ~Reading() {}

};