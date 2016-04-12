#ifndef GRADE_H
#define GRADE_H

class Grade {
private:
	const int maxScoreNum;
	int mNumScore;
	int *mScore;
public:
	Grade();
	~Grade();
	void pushScore(int);
	bool isFull();
	double avg();
	void show();
	int getNumScore();
	void setScore(int, int);
	Grade& operator=(const Grade&);
};

#endif