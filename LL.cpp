/*
  This is a worse version of student list.
  
  Author: Dieter Voegels
  Date: 12/6/17
*/
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//prototypes
void add(Node* &head, Node* &newNode);
void recursiveAdd(Node* &head, Node* previous, Node* current, Node* newNode);
void print(Node* head, Node* current);
void average(Node* head, Node* current);
void Delete(Node* &head, Node* previous, Node* current, int ID);

//main 
int main(){
  bool quit = true;
  char input[10];
  Node* head = NULL;

  //if the user is still using the program, loop
  while(quit){
    cout << "Add, Delete, Print, Average, Quit" << endl;
    cin >> input;
    cin.ignore();

    //add if the user types add
    if(strcmp(input, "add") == 0){
      cout << "What is the first name of the student?" << endl;
      char* fName = new char[100];
      cin.getline(fName, 100);
      cout << "What is the last name of the student?" << endl;
      char* lName = new char[100];
      cin.getline(lName, 100);
      cout << "What is the ID of the student?" << endl;
      int ID;
      cin >> ID;
      cin.ignore();
      cout << "What is the GPA of the student?" << endl;
      float GPA;
      cin >> GPA;
      cin.ignore();
      Student* newStudent = new Student(GPA, fName, lName, ID);
      Node* newNode = new Node(newStudent);
      newNode->setNext(NULL);
      add(head, newNode);
    }

    //delete if the user types delete
    if(strcmp(input, "delete") == 0){
      cout << "What is the ID of the student?" << endl;
      int ID;
      cin >> ID;
      cin.ignore();
      Delete(head, head, head, ID);
    }
    //print if the user types print
    if(strcmp(input, "print") == 0){
      Node* current = head;
      print(head, current);
    }
    //average the GPA's if they type GPA
    if(strcmp(input, "average") == 0){
      Node* current = head;
      average(head, current);
    }
    //quit the program if they type quit
    if(strcmp(input, "quit") == 0){
      //quit the program
      quit = false;
    }
  }
}

//add a node to the list
void add(Node* &head, Node* &newNode){
  //initialize current and previous nodes
  Node* current = head;
  Node* previous = head;
  if (current == NULL){
    head = newNode;
    cout << "You have created a new list and the student has been added to it" << endl;
  }
  else if(head->getStudent()->getID() > newNode->getStudent()->getID()){
    newNode->setNext(head);
    head = newNode;
  }
  else{
    recursiveAdd(head, previous, current, newNode);
  }
}

//recursivly add
void recursiveAdd(Node* &head, Node* previous, Node* current, Node* newNode){  
  if(current->getNext() == NULL){
    if(current->getStudent()->getID() < newNode->getStudent()->getID()){
      current->setNext(newNode);
    }
    else{
      previous->setNext(newNode);
      newNode->setNext(current);
    }
    return;
  }
  if(current->getStudent()->getID() < newNode->getStudent()->getID() && current->getNext() != NULL){
    recursiveAdd(head, current, current->getNext(), newNode);
    return;
  }
  else if(previous != current){
    previous->setNext(newNode);
    newNode->setNext(current);
    return;
  }
}

//print all of the nodes
void print(Node* head, Node* current){
  if(current != NULL){
    Student* student = current->getStudent();
    cout << student->getfName();
    cout << " ";
    cout << student->getlName();
    cout << ", ";
    cout << student->getID();
    cout << ", ";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << student->getGPA() << endl;
    print(head, current->getNext());
    return;
  }
  else if(current == head){
    cout << "The list does not exist" << endl;
    return;
  }
}

//average all of GPA's
void average(Node* head, Node* current){
  if(current == head && current == NULL){
    cout << "The list does not exist" << endl;
    return;
  }

  float averageGPA = 0;
  int total;
  
  while(current != NULL){
    averageGPA += current->getStudent()->getGPA();
    total++;
    current = current->getNext();
  }

  averageGPA = averageGPA/total;
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "Average GPA: " << averageGPA << endl;
}

//Delete a node from the nodes
void Delete(Node* &head, Node* previous, Node* current, int ID){
  if(current == NULL){
    cout << "The list does not exist" << endl;
    return;
  }
  else if(current->getStudent()->getID() == ID){
    if(current == head){
      head = current->getNext();
      delete current;
      return;
    }
    else{
      previous->setNext(current->getNext());
      delete current;
      return;
    }
  }
  else{
    Delete(head, current, current->getNext(), ID);
  }
}
