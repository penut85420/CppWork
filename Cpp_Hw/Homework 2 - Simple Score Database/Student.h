#ifndef STUDENT_H
#define STUDENT_H
#include "main.h"
class Student {
private:
	string mName, mID;
	Grade mGrade;
public:
	Student();
	~Student();
	void setStudent(string, string);
	void show(int);
	string getName();
	void addScore();
	double avg();
	int getNumScore();
	void setScore(int, int);
	Student& operator=(const Student&);
	void save(ostream&);
	void load(istream&);
};
#endif