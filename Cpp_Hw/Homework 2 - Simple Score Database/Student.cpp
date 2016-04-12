#include "main.h"

Student::Student() : maxNameSize(11), maxIdSize(7) {
	mName = new char[maxNameSize];
	mID = new char[maxIdSize];
}

Student::~Student() {
	delete [] mName;
	delete [] mID;
}

void Student::setStudent(string name, string ID) {
	strcpy(mName, name.c_str());
	strcpy(mID, ID.c_str());
}

void Student::show(int mode) {
	cout << "名字：" << mName << endl
		 << "學號：" << mID << endl;
	if (!mode) cout << "平均：" << mGrade.avg() << endl;
	else {
		cout << "成績：";
		mGrade.show();
	}
}

string Student::getName() {
	return mName;
}

void Student::addScore() {
	if (mGrade.isFull()) {
		cout << "超過個人最多成績筆數無法加入資料庫內" << endl;
		return;
	}
	int score;
	
	cout << "請輸入成績：";
	cin >> score;
	mGrade.pushScore(score);
}

int Student::getNumScore() {
	return mGrade.getNumScore();
}

void Student::setScore(int index, int score) {
	mGrade.setScore(index - 1, score);
}

Student& Student::operator=(const Student &s) {
	mName = s.mName;
	mID = s.mID;
	mGrade = s.mGrade;
	return *this;
}

void Student::save(ostream &os) {
	os.write(mName, maxNameSize);
	os.write(mID, maxIdSize);
	mGrade.save(os);
}

void Student::load(istream &fin) {
	fin.read(mName, maxNameSize);
	fin.read(mID, maxIdSize);
	mGrade.load(fin);
}