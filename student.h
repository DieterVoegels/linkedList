/*
  This is the student h file holding the variables and prototypes
  Dieter Voegels
  1/25/18
*/
#include <iostream>

using namespace std;

class Student{
 public:
  //prototypes
  Student(float newGPA, char* newfName, char* newlName, int newID);
  float getGPA();
  char* getfName();
  char* getlName();
  int getID();
 private:
  //variables
  float GPA;
  char* fName;
  char* lName;
  int ID;
};
