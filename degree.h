
#ifndef DEGREE_H_
#define DEGREE_H_
#include <string>
enum Degree {SOFTWARE, SECURITY, NETWORK};//3 types of degrees

// RUBRIC C: The enumerated data types for the degree programs are correctly defined.
// the following array of strings will return a string instead of the index int from Degree
static const std::string degreeTypeStrings[] = { "SOFTWARE", "SECURITY", "NETWORK" };

#endif DEGREE_H_