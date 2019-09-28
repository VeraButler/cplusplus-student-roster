#include <iostream>
#include "softwareStudent.h"
using std::cout;

// constructor
SoftwareStudent::SoftwareStudent()
{
	setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string newID, string newFName, string newLName, string newEmail, int newAge, int* newNumDaysToComplete, Degree type) {
	setDegreeType(SOFTWARE);
}

Degree SoftwareStudent::getDegreeType()
{
	return SOFTWARE; //now the function is not virtual
}

void SoftwareStudent::setDegreeType(Degree degreetype) {
	this->degreeType = SOFTWARE; //we set this here because it is known what type of degree the student has
}

void SoftwareStudent::print()
{
	this->Student::print();//call print method from parent Student class
	cout << "SOFTWARE" << "\n"; //adds degree to the parent print function
}

//destructor
SoftwareStudent::~SoftwareStudent()
{
	// call super destructor from Student in case it needs to release something
	Student::~Student();
	// delete `this`
	delete this;
}
