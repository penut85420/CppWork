#include "FredPtr.h"
#include <assert.h>
    
FredPtr::FredPtr(Fred* ptr) : mPtr(ptr) { }
    
FredPtr::~FredPtr() {
    deallocate();
}
    
void FredPtr::deallocate() {
    delete mPtr; 
    mPtr = 0;
}
    
FredPtr& FredPtr::operator=(Fred* ptr) {
    deallocate();
    mPtr = ptr;
    return *this;
}

FredPtr& FredPtr::operator=(const FredPtr &rhs) {
	if (&rhs == this) return *this;

	deallocate();
	if (rhs.mPtr) 
		mPtr = new Fred(*rhs.mPtr);
	else mPtr = 0;
	return *this;
}

FredPtr::FredPtr(const FredPtr &src) {

}
    
Fred* FredPtr::operator->() {
    assert(mPtr != 0);
    return mPtr;
}
    
Fred& FredPtr::operator*() {
    assert(mPtr != 0);
    return *mPtr;
}
    
// �ϱo FredPtr ���󤣦A�֦��@ Fred ����
Fred* FredPtr::relinguishOwnership() {
    Fred* old = mPtr;
    mPtr = 0;
    return old;
}