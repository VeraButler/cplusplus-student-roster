#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "degree.h"
using std::string;
// header guard

// content - forward declarations for all of the identifiers other files to be able to see
// functions are defined in analogous .cpp file
// declarations are put in header files

// student class
class Student {
	//RUBRIC D1: The base class Student is correctly created 
	//by correctly including each of the given variables.
	// protected members can only be accessed by derived classes
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* numberOfDaysToCompleteCourse;
	//Degree type - enumerated value: SOFTWARE, SECURITY, NETWORK
	Degree degreeType;


// public members can be accessed by all classes
public:// public itema are visibile everywhere in the application
	const static int numberOfDaysToCompleteCourseArraySize = 3;
	//default constructor
	Student();

	//RUBRIC D2D: The constructor function in the Student class 
	//accurately uses all of the input parameters from the data table.
	//paramaterized constructor
	Student(string newID, string newFName, string newLName, string newEmail, int newAge, int newNumDaysToComplete[], Degree newDegreeType);

	// RUBRIC D2A: The accessor function in the Student class for 
	// each instance variable from part D1 is functional and complete.
	//getters for each instance of field
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumberOfDaysToCompleteCourse();
	
	// RUBRIC 10: The virtual getDegreeProgram()
    //function is provided with empty implementation.
	virtual Degree getDegreeType() = 0; //VIRTUAL; cannot instatiate a Degree object

	// RUBRIC D2B: The mutator function in the Student class 
	// for each instance variable from part D1 is functional or complete.
	//the setters
	void setStudentID(string newID);
	void setFirstName(string newFName);
	void setLastName(string newLName);
	void setEmailAddress(string newEmail);
	void setAge(int newAge);
	void setNumberOfDaysToCompleteCourse(int newNumDaysToComplete[]);
	virtual void setDegreeType(Degree d) = 0; //VIRTUAL- must be set to ZERO to force derived class to create it's own version of the function
	
	// RUBRIC D2F: The virtual print() function in 
	//the Student class accurately prints specific student data.
	virtual void print() = 0;

	// RUBRIC D2E: The destructor function is implemented to release memory.
	// destructor
	~Student();
};

#endif //STUDENT_H_