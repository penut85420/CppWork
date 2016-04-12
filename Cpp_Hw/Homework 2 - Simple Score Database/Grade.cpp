#include "main.h"

Grade::Grade() : maxScoreNum(6), mNumScore(0) {
	mScore = new int[maxScoreNum];
}

Grade::~Grade() {
	delete [] mScore;
}

void Grade::pushScore(int score) {
	if (!isFull()) mScore[mNumScore++] = score;
}

bool Grade::isFull() {
	if (mNumScore == maxScoreNum) return true;
	return false;
}

double Grade::avg() {
	double avg = 0;
	for (int i = 0; i < mNumScore; i++)
		avg += mScore[i];
	return avg / mNumScore;
}

void Grade::show() {
	for (int i = 0; i < mNumScore; i++)
		cout << mScore[i] << " ";
	cout << endl;
}

int Grade::getNumScore() {
	return mNumScore;
}

void Grade::setScore(int index, int score) {
	mScore[index] = score;
}

Grade& Grade::operator=(const Grade &g) {
	mNumScore = g.mNumScore;
	for (int i = 0; i < g.mNumScore; i++) {
		mScore[i] = g.mScore[i];
		cout << mScore[i] << " ";
	}
	return *this;
}

void Grade::save(ostream &os) {
	os.put(mNumScore);
	os.write((char*)mScore, sizeof(int) * maxScoreNum);
}

void Grade::load(istream &fin) {
	char tmp;
	fin.get(tmp); mNumScore = tmp;
	fin.read((char*)mScore, sizeof(int) * maxScoreNum);
}