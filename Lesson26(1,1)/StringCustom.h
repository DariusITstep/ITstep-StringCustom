#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class StringCustom {

private:
    char* str;
    int len;

    static int count;

    void safeCopy(const char* input);

public:
    StringCustom();
    StringCustom(int size);
    StringCustom(const char* input);
    StringCustom(const StringCustom& other);

    ~StringCustom();

    void inputString();
    void outputString() const;

    static int getCount();

    StringCustom operator*(const StringCustom& other) const;
};