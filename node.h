//From Stone Y.
//To Dieter V.
#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<string.h>
#include"student.h"
using namespace std;

class Node
{
 public:
  Node(Student*);
  ~Node();
  void setNext(Node*);
  Node* getNext();
  Student* getStudent();

 private:
  Student* s;
  Node* n;
};

#endif
