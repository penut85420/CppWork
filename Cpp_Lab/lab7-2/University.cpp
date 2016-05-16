#include "main.h"

University::University(istream &in) {
	in >> mName >> numCollege;
	for (int i = 0; i < numCollege; i++)
		mCollege.push_back(new College(in));
}

University::University() { }

University::~University() {
	for (int i = 0; i < numCollege; i++)
		delete mCollege[i];
}

void University::print(ostream &os) {
	os << "學校名稱：" << mName << endl;
	/*for (int i = 0; i < numCollege; i++)
		mCollege[i]->print(os);*/
}

void University::unitTest() {
	print(cout);
}

string University::getName(string tag) {
	cout << "請輸入" << tag << "名稱：";
	getline(cin, tag);
	return tag;
}

bool University::checkString(string s) {
	if (s == "") {
		cout << "未輸入任何資料" << endl;
		return false;
	}
	return true;
}

void University::query() {
    int cmd;
	string s;
	while (1) {
		system("cls");
		cout << "[1] 查詢教師基本資料\n"
			 << "[2] 查詢課程基本資料\n"
			 << "[3] 查詢教師開授課程\n"
			 << "[4] 查詢系所課程\n"
			 << "[5] 查詢系所教師\n"
			 << "[6] 新增課程\n"
			 << "[7] 新增教師\n"
			 << "[8] 離開系統\n"
			 << " > ";
		cin >> cmd; cin.get();
		if (cmd == 8) return;
		else if (cmd == 1) {
			s = getName("教師");
			if (checkString(s))
				viewTeacher(s, cout);
		} else if (cmd == 2) {
			s = getName("課程");
			if (checkString(s))
				viewCourse(s, cout);
		} else if (cmd == 3) {

		}
		system("PAUSE");
	}
}

void University::viewTeacher(string name, ostream &os) {
	for (auto it = mCollege.begin();
			it != mCollege.end(); it++) {
		(*it)->viewTeacher(name, os);
	}
}

void University::viewCourse(string name, ostream &os) {
	for (auto it = mCollege.begin();
			it != mCollege.end(); it++) {
		(*it)->viewCourse(name, os);
	}
}