
#ifndef SECURITYSTUDENT_H_

#include <string>
#include "student.h"
#include "degree.h"

/*
RUBRIC D3: 

All 3 classes are a subclass of the Student class using the files created in part B. 

Each subclass overrides the getDegreeProgram() function. 

Each subclass has a data member to hold the enumerated type, using the types defined in part C.

*/

class SecurityStudent : public Student //Security student is a derived class of Student
{
	// all intance fields are inherited from Student class
public:
	//default constructor
	SecurityStudent();
	//paramterized constructor
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* numDaysToCompleteCourse,
		Degree degreeType
	);

	//The following virtual methods from Student are overridden in this class
	Degree getDegreeType();
	void setDegreeType(Degree degree);
	void print();

	//destructor
	~SecurityStudent();
};

#endif //SECURITYSTUDENT_H_
