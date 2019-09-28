
#include <iostream>
#include "securityStudent.h"
using std::cout;

// constructor
SecurityStudent::SecurityStudent()
{
	setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string newID, string newFName, string newLName, string newEmail, int newAge, int * newNumDaysToComplete, Degree type) {
	setDegreeType(SECURITY);
}

Degree SecurityStudent::getDegreeType()
{
	return SECURITY; //now the function is not virtual
}

void SecurityStudent::setDegreeType(Degree degreetype) {
	this->degreeType = SECURITY; //we set this here because it is known what type of degree the student has
}

void SecurityStudent::print()
{
	this->Student::print();//call print method from parent Student class
	cout << "SECURITY" << "\n"; //adds degree to the parent print function
}

//destructor
SecurityStudent::~SecurityStudent()
{
	// call super destructor from Student in case it needs to release something
	Student::~Student();
	// delete `this`
	delete this;
}
