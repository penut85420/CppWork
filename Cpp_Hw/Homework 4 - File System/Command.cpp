#include "Command.h"
#include <iostream>
using namespace std;

Command::Command(void) {
	mRoot = new EntryFolder("root", NULL);
	mNowFolder = mRoot;
}

Command::~Command(void) { }

void Command::query() {
	int cmd;
	while (true) {
		cout << "目前資料夾 " << mNowFolder->getPath() << "/" << endl;
		cout << "[ 1] 回到上一層資料夾\t[ 8] 搜尋檔案或資料夾\n"
			<< "[ 2] 進入下一層資料夾\t[ 9] 列印目前資料匣內檔案\n"
			<< "[ 3] 增加一個檔案\t[10] 列印目前資料匣內檔案(包含子資料匣)\n"
			<< "[ 4] 列印檔案內容\t[11] 搜尋檔案內字串\n"
			<< "[ 5] 增加一個資料夾\t[12] 檔案或資料匣大小\n"
			<< "[ 6] 刪除檔案\t\t[13] 結束操作\n"
			<< "[ 7] 刪除資料夾及子資料夾\n > ";
		cin >> cmd;
		switch(cmd) {
		case  1:
			exitFolder(); break;
		case  2:
			cdFolder(); break;
		case  3:
			addFile(); break;
		case  4:
			printFile(); break;
		case  5:
			addFolder(); break;
		case  6:
			deleteFile(); break;
		case  7:
			deleteFolder(); break;
		case 13:
			return ; break;
		}
		system("PAUSE");
		system("CLS");
	}
}

void Command::exitFolder() {
	mNowFolder = mNowFolder->lastFolder();
}

void Command::addFile() {
	string name = getName(false), content;
	if (!isEmpty(mNowFolder->search(name, false))) {
		cout << "已存在相同名稱的檔案" << endl;
		return ;
	}
	cout << "請輸入檔案內容：";
	cin >> content;
	EntryFile *newFile = new EntryFile(name, content);
	mNowFolder->addEntry(newFile);
}

void Command::addFolder() {
	string name = getName(true);
	if (!isEmpty(mNowFolder->search(name, true))) {
		cout << "已存在相同名稱的資料夾" << endl;
		return ;
	}
	EntryFolder *newFolder = new EntryFolder(name, mNowFolder);
	mNowFolder->addEntry(newFolder);
}

string Command::getName(bool isFolder) {
	string name;
	if (isFolder) cout << "請輸入資料夾名稱：";
	else cout << "請輸入檔案名稱：";
	cin >> name;
	return name;
}

void Command::cdFolder() {
	string name = getName(true);
	auto result = mNowFolder->search(name, true);
	if (!isEmpty(result)) mNowFolder = (EntryFolder*)*result;
	else cout << "無此資料夾" << endl;
}

void Command::printFile() {
	string name = getName(false);
	auto result = mNowFolder->search(name, false);
	if (!isEmpty(result)) ((EntryFile*)*result)->print();
	else cout << "無此檔案" << endl;
}

void Command::deleteFile() {
	string name = getName(false);
	auto result = mNowFolder->search(name, false);
	if (!isEmpty(result)) mNowFolder->removeEntry(result);
}

bool Command::isEmpty(EntryIt it) {
	if (it == mNowFolder->dump()) return true;
	return false;
}

void Command::deleteFolder() {

}