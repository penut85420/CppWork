#include "main.h"

Student::Student() {

}

Student::~Student() {

}

void Student::setStudent(string name, string ID) {
	mName = name;
	mID = ID;
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
	os.put(mName.length());
	os.write((char*)mName.c_str(), mName.length());

	os.put(mID.length());
	os.write((char*)mID.c_str(), mID.length());
}

void Student::load(istream &fin) {
	
}