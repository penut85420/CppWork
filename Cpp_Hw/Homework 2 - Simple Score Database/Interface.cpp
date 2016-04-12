#include "main.h"

int displayMenu(Menu menuType, const char dataName[]) {
	char opCode;

	cout << "請選擇下列操作：" << endl;
	if (menuType == Main) {
		cout << "[1] 輸入資料庫檔案名稱" << endl
			 << "[2] 離開系統" << endl;
	} else if (menuType == Operation) {
		cout << "[1] 增加一名學生" << endl
			 << "[2] 對一學生增加一新成績" << endl
			 << "[3] 查詢一學生之所有成績" << endl
			 << "[4] 更改一學生之成績" << endl
			 << "[5] 刪除某一學生" << endl
			 << "[6] 列印顯示所有資料庫中之資料" << endl
			 << "[7] 存檔並關閉 " << dataName << " 檔案" << endl
		     << "[8] 結束" << endl;
	}
	do {
		cout << " > "; 
		cin >> opCode;
	} while (!(opCode > '0' && opCode <= '0' + menuType));

	return opCode - '0';
}