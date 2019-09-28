#ifndef SOFTWARESTUDENT_H_
#include <string>
#include "student.h"
#include "degree.h"

/*
RUBRIC D3:

All 3 classes are a subclass of the Student class using the files created in part B.

Each subclass overrides the getDegreeProgram() function.

Each subclass has a data member to hold the enumerated type, using the types defined in part C.

*/


class SoftwareStudent : public Student //Software student is a derived class of Student
{
	// all intance fields are inherited from Student class
public:
	//default constructor
	SoftwareStudent();
	//paramterized constructor
	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		// RUBRIC E1: The array of pointers created to hold the data 
		// in the classRosterArray table is complete and correct.
		int* numDaysToCompleteCourse,
		Degree degreeType
	);

	//The following virtual methods from Student are overridden in this class
	Degree getDegreeType();
	void setDegreeType(Degree degree);
	void print();

	//destructor
	~SoftwareStudent();
};

#endif //SOFTWARESTUDENT_H_
