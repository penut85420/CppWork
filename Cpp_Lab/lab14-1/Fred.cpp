#include "Fred.h"
#include <iostream>
using namespace std;
    
int Fred::mSerialID = 0;
    
Fred::Fred() : mObjectID(mSerialID++) {
    cout << "Fred::ctor\tID=" << mObjectID << endl; 
}
    
Fred::~Fred() {
    cout << "Fred::dtor\tID=" << mObjectID << endl;
}
    
void Fred::service() {
    cout << "Fred::service()\tID=" << mObjectID << endl; 
}