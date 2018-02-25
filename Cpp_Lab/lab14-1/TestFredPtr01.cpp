#include "Fred.h"
#include "FredPtr.h"
#include <iostream>
using namespace std;
    
void main() {
    FredPtr ptrFred1, ptrFred2(new Fred);
    // ptrFred2 �֦��@ Fred ���� (ID=0)
    
    ptrFred1 = new Fred; // ptrFred1 �֦��� Fred ���� (ID=1)
    
    ptrFred1 = 0; // �R���� Fred ���� (ID=1)
    
    ptrFred2->service();
    (*ptrFred2).service();
    
    Fred *ptrFred;
    ptrFred = ptrFred2.relinguishOwnership();
    delete ptrFred;     // without this line, memory is
                        //  leaking �R�� Fred ���� (ID=0)
	cin.get();
}