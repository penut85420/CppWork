#include "main.h"

Class::Class() : maxStudentNum(100), mNumStudent(0) {
	mStudent = new Student[maxStudentNum];
}

Class::~Class() {
	delete [] mStudent;
}

void Class::addStudent() {
	string name, ID;
	cout << "請輸入學生姓名：";
	cin >> name;
	cout << "請輸入學生學號：";
	cin >> ID;
	mStudent[mNumStudent++].setStudent(name, ID);
	cout << "新增完成" << endl;
}

void Class::addScore() {
	int i = findStudent();
	if (i != -1) mStudent[i].addScore();
	cout << "新增完成" << endl;
}

void Class::show() {
	if (isEmpty()) return;
	for (int i = 0; i < mNumStudent; i++) {
		mStudent[i].show(0);
	}
}

void Class::showStudent() {
	if (isEmpty()) return;
	int i = findStudent();
	if (i != -1) mStudent[i].show(1);
}

int Class::findStudent() {
	string name; int i;
	cout << "請輸入學生姓名：";
	cin >> name;
	for (i = 0; i < mNumStudent; i++)
		if (name == mStudent[i].getName()) break;
	
	if (i == mNumStudent) {
		cout << "查無此學生" << endl;
		return -1;
	}
	return i;
}

void Class::fixScore() {
	int i = findStudent(), select, score;
	if (!mStudent[i].getNumScore()) {
		cout << "此學生尚未輸入任何成績";
		return;
	}
	mStudent[i].show(1);
	cout << "請問要修改第幾筆成績：";
	do {
		cin >> select;
	    if (select > mStudent[i].getNumScore() || select < 1)
		    cout << "無此成績，請重新輸入：";
	} while (select > mStudent[i].getNumScore() || select < 1);
	cout << "請輸入成績：";
	cin >> score;
	mStudent[i].setScore(select, score);
	cout << "成績修改完成" << endl;
}

void Class::deleteStudent() {
	if (isEmpty()) return;
	int i = findStudent();
	mNumStudent--;
	mStudent[i] = mStudent[mNumStudent];
}

bool Class::isEmpty() {
	if (!mNumStudent) {
		cout << "資料庫內沒有任何資料" << endl;
		return true;
	}
	return false;
}

void Class::save() {
	ofstream fout(className, ios::out, ios::binary);
	fout.put(mNumStudent);
	for (int i = 0; i < mNumStudent; i++)
		mStudent[i].save(fout);
}

void Class::load(char className[]) {
	ifstream fin(className, ios::in | ios::binary);
	if (!fin) return;
	char tmp;
	fin.get(tmp); mNumStudent = tmp;
	for (int i = 0; i < mNumStudent; i++)
	    mStudent[i].load(fin);
}

void Class::query() {
	int cmd;
	do {
		cmd = displayMenu(Main, "none");
		if (cmd == 1) {
			cout << "請輸入檔案名稱：";
			cin >> className;
			load(className);
			system("CLS");
			do {
				cmd = displayMenu(Operation, className);
				if (cmd == 1) addStudent();
				else if (cmd == 2) addScore();
				else if (cmd == 3) showStudent();
				else if (cmd == 4) fixScore();
				else if (cmd == 5) deleteStudent();
				else if (cmd == 6) show();
				else if (cmd == 7) save();
				if (cmd != 7 && cmd != 8) system("PAUSE");
				system("CLS");
			} while (cmd != 8 && cmd != 7);
		}
	} while (cmd != 2);
}