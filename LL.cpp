/*
  This program tests node.h
  
  Author: Dieter Voegels
  Date: 12/6
*/
#include <iostream>
#include "node.h"

using namespace std;

void setNext(node* Node, node* nextNode);

int main(){
  //create the student
  student* S = new student;
  //create nodes
  node* N = new node(S);
  //print out N's student value
  cout << N->getStudent()->getValue() << endl;
  node* N1 = new node(S);
  //set N's next node to N1
  setNext(N, N1);
  //print out N's next node's student value
  cout << N->getNextNode()->getStudent()->getValue() << endl;
}

//sets Node's next node to nextNode
void setNext(node* Node, node* nextNode){
  Node->setNextNode(nextNode);
}
