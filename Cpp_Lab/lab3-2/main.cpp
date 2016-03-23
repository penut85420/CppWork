#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main()
{
	int i, nItems;
	struct SaleItem *items[100];

	initialize(&nItems, items);

	for (i = 0; i < nItems; i++)
		(*items[i]->print)(items[i]);
	// 請在此處撰寫一個迴圈來列印所有 nItems 個商品
	// 的內容，這個迴圈的內容應該只有一個簡單的函式
	// 呼叫，通通透過欄位 print 這個函式指標變數來呼叫，
	// 因為此時已經將所有商品抽象化看成是一致的 SaleItem 
	// 的東西了

	for (i = 0; i < nItems; i++)
		free(items[i]); // 請注意此處也不需要區分資料的種類

	printf("Press enter to continue...");
	getchar();
}