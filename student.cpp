#include<iostream>
#include<iomanip>
#include "student.h" // insert the contents of student.h; double quotes required
using namespace std;

// implementation of Student Class
// if class implementation does not change then it won't need to be recompiled
Student::Student() { //empty constructor will set all to default values
	{
		this->studentID = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		// create a NEW array dynamically - MUST because it's VIRTUAL
		this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseArraySize]; // create new array and use destrctor to dispose of it
		for (int i = 0; i < numberOfDaysToCompleteCourseArraySize; i++) this->numberOfDaysToCompleteCourse[i] = 0;
	
		 // Do not set Degree Type in constructor because it is not known
	}
}

Student::Student(string newID, string newFName, string newLName, string newEmail, int newAge, int newNumDaysToComplete[], Degree newDegreeType) {
	this->studentID = newID;
	this->firstName = newFName;
	this->lastName = newLName;
	this->emailAddress = newEmail;
	this->age = newAge;
	//Need a new array no matter which contructor is called
	//NOTE: making a copy is IMPORTANT becuase if the object simply points at the same array
	// it can be manipulated/destroyed EXTERNALLY
	this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseArraySize];
	// loop through array
	for (int i = 0; i < 3; i++) this->numberOfDaysToCompleteCourse[i] = newNumDaysToComplete[i];
}

//getters
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int * Student::getNumberOfDaysToCompleteCourse() {
	return numberOfDaysToCompleteCourse;
}

// setters
void Student::setStudentID(string newID)
{
	this->studentID = newID;
}
void Student::setFirstName(string newFName)
{
	this->firstName = newFName;
}
void Student::setLastName(string newLName)
{
	this->lastName = newLName;
}
void Student::setEmailAddress(string newEmail)
{
	this->emailAddress = newEmail;
}
void Student::setAge(int newAge) 
{
	this->age = newAge;
}
void Student::setNumberOfDaysToCompleteCourse(int newNumDaysToComplete[]) {
	if (this->numberOfDaysToCompleteCourse != nullptr) {
		delete[] this->numberOfDaysToCompleteCourse;
		this->numberOfDaysToCompleteCourse = nullptr;
	}

	this->numberOfDaysToCompleteCourse = new int[numberOfDaysToCompleteCourseArraySize];
	for (int i = 0; i < 3; i++)
		this->numberOfDaysToCompleteCourse[i] = newNumDaysToComplete[i];
}

void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(10)<< firstName;
	cout << left << setw(10)<< lastName;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(10) << age;
	cout << left << setw(10) << numberOfDaysToCompleteCourse[0];
	cout << left << setw(10) << numberOfDaysToCompleteCourse[1];
	cout << left << setw(10) << numberOfDaysToCompleteCourse[2];
}


//destructor
Student::~Student()
{	// if numberOfdaysToComplete course is not a nullptr
	// then delete numberOfDaysToComplereCourse
	// then set numberOfDaysToCompleteCourse = nullptr
	if (numberOfDaysToCompleteCourse != nullptr) {
		delete[] numberOfDaysToCompleteCourse;
		numberOfDaysToCompleteCourse = nullptr;
	}
};



