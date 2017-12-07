/*
  This is the node h file. This program has the prototypes for getting the next node, setting the next node, getting the student, and setting the student. It also contains the constructor and destructor.

  Author: Dieter Voegels
  Date: 12/6
*/
#include <iostream>
#include "student.h"

using namespace std;

class node{
 public:
  node(student* S);
  ~node();
  node* getNextNode();
  void setNextNode(node* newNext);
  student* getStudent();
  void setStudent();
 private:
  student* S;
  node* next;
};
