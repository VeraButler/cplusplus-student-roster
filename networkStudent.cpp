
#include <iostream>
#include "networkStudent.h"
using std::cout;

// constructor
NetworkStudent::NetworkStudent()
{
	setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(string newID, string newFName, string newLName, string newEmail, int newAge, int* newNumDaysToComplete, Degree type) {
	setDegreeType(NETWORK);
}

Degree NetworkStudent::getDegreeType()
{
	return NETWORK; //now the function is not virtual
}

void NetworkStudent::setDegreeType(Degree degreetype) {
	this->degreeType = NETWORK; //we set this here because it is known what type of degree the student has
}

void NetworkStudent::print()
{
	this->Student::print();//call print method from parent Student class
	cout << "NETWORK" << "\n"; //adds degree to the parent print function
}

//destructor
NetworkStudent::~NetworkStudent()
{
	// call super destructor from Student in case it needs to release something
	Student::~Student();
	// delete `this`
	delete this;
}
