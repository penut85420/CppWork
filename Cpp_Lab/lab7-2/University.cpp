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
	for (int i = 0; i < numCollege; i++)
		mCollege[i]->print(os);
	system("PAUSE");
}

void University::unitTest() {
	print(cout);
}

string University::getName(string tag) {
	cout << "請輸入" << tag << "名稱：";
	cin >> tag;
	return tag;
}

void University::query() {
    int cmd;
	string s;
	while (1) {
		cout << "[1] 查詢教師基本資料\n"
			 << "[2] 查詢課程基本資料\n"
			 << "[3] 查詢教師開授課程\n"
			 << "[4] 查詢系所課程\n"
			 << "[5] 查詢系所教師\n"
			 << "[6] 新增課程\n"
			 << "[7] 新增教師\n"
			 << "[8] 離開系統\n"
			 << " > ";
		cin >> cmd;
		if (cmd == 8) return;
		else if (cmd == 1) {
			s = getName("教師");

		}
	}
}