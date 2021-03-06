#include "Fred.h"
#include "FredPtr.h"
#include <iostream>
using namespace std;
    
void main() {
    FredPtr ptrFred1, ptrFred2(new Fred);
    // ptrFred2 擁有一 Fred 物件 (ID=0)
    
    ptrFred1 = new Fred; // ptrFred1 擁有該 Fred 物件 (ID=1)
    
    ptrFred1 = 0; // 刪除該 Fred 物件 (ID=1)
    
    ptrFred2->service();
    (*ptrFred2).service();
    
    Fred *ptrFred;
    ptrFred = ptrFred2.relinguishOwnership();
    delete ptrFred;     // without this line, memory is
                        //  leaking 刪除 Fred 物件 (ID=0)
	cin.get();
}