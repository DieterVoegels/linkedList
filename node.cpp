//This is the node cpp file. It sets the next node, gets the node, and sets the student
#include<iostream>
#include "node.h"

using namespace std;

node::node(student* newS){
  S = newS;
}
node::~node(){
  delete S;
}
void node::setNextNode(node* newNext){
  next = newNext;
}
node* node::getNextNode(){
  return next;
}
student* node::getStudent(){
  return S;
}
