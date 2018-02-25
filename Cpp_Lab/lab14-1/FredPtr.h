#pragma once
#include "Fred.h"

class FredPtr {
public:
    FredPtr(Fred* = 0);
    ~FredPtr();
    void deallocate();
    FredPtr& operator=(Fred*);
    Fred* operator->();
    Fred& operator*();
    Fred* relinguishOwnership();

private:
    Fred* mPtr;
    FredPtr& operator=(const FredPtr&); // unimplemented
    FredPtr(const FredPtr&);            // unimplemented
};