#ifndef CLASS_H
#define CLASS_H
#include "Student.h"

class Class {
private:
	Student *mStudent;
	int mNumStudent;
	const int maxStudentNum;
	char className[512];
public:
	Class();
	~Class();
	void addStudent();
	void show();
	void query();
	void addScore();
	void showStudent();
	int findStudent();
	void fixScore();
	void deleteStudent();
	bool isEmpty();
	void save();
	void load(char[]);
};

#endif CLASS_H