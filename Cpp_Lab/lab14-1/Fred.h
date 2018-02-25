#pragma once

class Fred {
public:
    Fred();
    ~Fred();
    void service();

private:
    static int mSerialID;
    const int mObjectID;
};