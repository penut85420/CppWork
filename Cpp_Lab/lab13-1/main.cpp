#include <iostream>
#include <fstream>
using namespace std;
    
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include "ForeignGraduateStudent.h"
#include "LoggedStudentList.h"
#include "Iterator.h"
    
void main()
{
    ofstream logfile("main2.log");
    LoggedStudentList sList(logfile);
    sList.appendEntry(new UndergraduateStudent("Mary Chen", "111111111", 
                                    "0933111111", 
                                    "Business",
                                    "John Viega"));
    sList.appendEntry(new UndergraduateStudent("John Wang", "222222222", 
                                    "0928222222", 
                                    "Computer Science",
                                    "Dan Smart"));
    sList.appendEntry(new GraduateStudent("Mel Lee", "333333333", 
                                    "0968333333", 
                                    "Mechanical Engineering",
                                    "Ron Rivest"));
    sList.appendEntry(new GraduateStudent("Bob Tsai", "444444444", 
                                    "0930444444", 
                                    "Electrical Engineering",
                                    "Alan Laub"));
    sList.appendEntry(new ForeignGraduateStudent("Ron Yang", "555555555", 
                                    "0918555555", 
                                    "Computer Science",
                                    "Allen Gersho",
                                    "Singapore"));
    
    int i;
    StudentListIterator iter1(sList), iter2(sList);
    for (i=0, iter1.reset(); 
            iter1.hasMoreData(); iter1.next(), i++)
    {
        cout << i << ":";
        iter1->display(cout);
        cout << endl;
    }
    
    sList.find("222222222")->display(cout); cout << " found!!" << endl;
    
    if (sList.deleteEntry("444444444"))
        cout << "Bob Tsai's entry deleted successfully!\n";
    else
        cout << "Bob Tsai's entry deletion failed!\n";
    
    if (sList.find("444444444") == 0)
        cout << "Can not find Bob Tsai's entry!\n";
    
    
    cout << endl;
    for (iter1.reset(); iter1.hasMoreData(); iter1.next())
    {
        for (iter2=iter1, iter2.next(); 
                iter2.hasMoreData(); iter2.next())
        {
            if (iter1->ofTheSameDepartment(*iter2))
            {
                cout << "The following two students"
                        " are of the same department:\n";
                iter1->display(cout);
                cout << endl;
                iter2->display(cout);
                cout << endl;
            }
        }
    }
    
    cout << endl;
    for (iter1.reset(); iter1.hasMoreData(); iter1.next())
        if (iter1->matchID("333333333"))
            sList.insertEntry(iter1, 
            new UndergraduateStudent("Carol Chen", "333331111", 
                                        "0933333111", "Business",
                                        "John Fowler"));
    for (i=0; i<sList.size(); i++)
    {
        sList[i]->display(cout);
        cout << endl;
    }
    
    sList.dump();
}