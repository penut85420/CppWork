#include <iostream>
#include "Student.h"
#include "StudentList.h"
using namespace std;

void main()
{
    StudentList sList;
    sList.appendEntry(new Student("Mary Chen", "111111111", 
                                    "0933111111", "Business"));
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
        
    sList.find("222222222")->display(cout); cout << endl;

    if (sList.deleteEntry("444444444"))
        cout << "Bob Tsai's entry deleted successfully!\n";
    else
        cout << "Bob Tsai's entry deletion failed!\n";

    if (sList.find("444444444") == 0)
        cout << "Can not fine Bob Tsai's entry!\n";
	system("PAUSE");
}