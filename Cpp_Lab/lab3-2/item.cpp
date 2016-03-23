#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void printBook(struct SaleItem *book) {
	struct Book *bPtr = (struct Book *)book;

	printf("Book name is %s\n", bPtr->title);
	printf("     author is %s\n", bPtr->author);
	printf("     publisher is %s\n", bPtr->publisher);
	printf("     price is %f\n\n", bPtr->price);
}

void printMagazine(struct SaleItem *magazine) {
	struct Magazine *mPtr = (struct Magazine *)magazine;

	printf("Magazine name is %s\n", mPtr->title);
	printf("         issue is %s\n", mPtr->issue);
	printf("         month/year is %s/%s\n", 
		mPtr->month, mPtr->year);
	printf("         publisher is %s\n", mPtr->publisher);
	printf("         price is %f\n\n", mPtr->price);
}

void printVCD(struct SaleItem *vcd) {
	struct VCD *vPtr = (struct VCD *)vcd;

	printf("VCD name is %s\n", vPtr->title);
	printf("    series is %s\n", vPtr->seriesTitle);
	printf("    casts are %s\n", vPtr->casts);
	printf("    year is %s\n", vPtr->year);
	printf("    producer is %s\n", vPtr->producer);
	printf("    price is %f\n\n", vPtr->price);
}

void initialize(int *nItems, struct SaleItem *items[]) {
	struct Book *bPtr;
	struct Magazine*mPtr;
	struct VCD *vPtr;

	bPtr = (struct Book*) malloc(sizeof(struct Book)); // 配置
	items[0] = (struct SaleItem *) bPtr; // 強制型態轉換
	bPtr->size = sizeof(struct Book);  // 結構佔記憶體大小
	bPtr->print = printBook;  // 指向列印本結構之函式
	strcpy(bPtr->title, 
		"Harry Potter and the Prisoner of Azkaban ");
	strcpy(bPtr->author, "J.K. Rowling ");
	strcpy(bPtr->publisher, "Bloomsbury");
	strcpy(bPtr->year, "2000");
	bPtr->price = 7.99;

	mPtr = (struct Magazine*) 
		malloc(sizeof(struct Magazine));
	items[1] = (struct SaleItem *) mPtr;
	mPtr->size = sizeof(struct Magazine);
	mPtr->print = printMagazine;
	strcpy(mPtr->title, "Reader's Digest");
	strcpy(mPtr->issue, "---");
	strcpy(mPtr->year, "2005");
	strcpy(mPtr->month, "03");
	strcpy(mPtr->publisher, 
		"The Reader's Digest Association, Inc.");
	mPtr->price = 13.5;

	vPtr = (struct VCD*) malloc(sizeof(struct VCD));
	items[2] = (struct SaleItem *) vPtr;
	vPtr->print = printVCD;
	strcpy(vPtr->title, "The Two Towers");
	strcpy(vPtr->seriesTitle, "Lord of the Rings");
	strcpy(vPtr->casts, "Elijah Wood, Ian Mackellen");
	strcpy(vPtr->year, "2003");
	strcpy(vPtr->producer, "Entertainment in Video");
	vPtr->price = 70;

	*nItems = 3;
}