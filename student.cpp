/*
  This is the cpp file for the student.h file. It returns things.
  Dieter Voegels
  1/25/18
*/
#include <iostream>
#include "student.h"

//constructor
Student::Student(float newGPA, char* newfName, char* newlName, int newID){
  GPA = newGPA;
  fName = newfName;
  lName = newlName;
  ID = newID;
}

//get the GPA of the student
float Student::getGPA(){
  return GPA;
}

//get the first name of the student
char* Student::getfName(){
  return fName;
}

//get the last name of the student
char* Student::getlName(){
  return lName;
}

//get the ID of the students
int Student::getID(){
  return ID;
}
