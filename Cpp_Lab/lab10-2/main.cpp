#include <iostream>
#include "Student.h"
#include "StudentList.h"
#include "Iterator.h"
using namespace std;

void main() {
	StudentList sList;
	sList.appendEntry(new Student("Mary Chen", "111111111", 
		"0933111111", 
		"Business"));
	sList.appendEntry(new Student("John Wang", "222222222", 
		"0928222222", 
		"Computer Science"));
	sList.appendEntry(new Student("Mel Lee", "333333333", 
		"0968333333", 
		"Mechanical Engineering"));
	sList.appendEntry(new Student("Bob Tsai", "444444444", 
		"0930444444", 
		"Electrical Engineering"));
	sList.appendEntry(new Student("Ron Yang", "555555555", 
		"0918555555", 
		"Computer Science"));

	// 列印串列中所有的 Student 物件
	int i;
	Iterator iter(sList);
	for (i=0, iter.reset(); iter.hasMoreData(); iter.next(), i++)
	{
		cout << i << ":";
		iter->display(cout);
		cout << endl;
	}
	cout << endl;

	// 檢查是否串列中有兩個學生是在同一個系所的           
	Iterator iter1(sList), iter2(sList);
	for (iter1.reset(); iter1.hasMoreData(); iter1.next())
	{
		for (iter2=iter1, iter2.next(); 
			iter2.hasMoreData(); iter2.next())
		{
			if (iter1->ofTheSameDepartment(*iter2))
			{
				cout << "The following two students are "
					"of the same department:\n";
				iter1->display(cout);
				cout << endl;
				iter2->display(cout);
				cout << endl;
			}
		}
	}

	// 在 id="333333333" 的學生之後再加入一個學生
	for (iter1.reset(); iter1.hasMoreData(); iter1.next())
		if (iter1->IDEquals("333333333"))
			sList.insertEntry(iter1, 
			new Student("Carol Chen", "333331111", 
			"0933333111", "Business"));
	for (i=0; i<sList.size(); i++)
		sList[i]->display(cout);
}