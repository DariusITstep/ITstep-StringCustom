#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class StringCustom {

private:
    char* str;
    int len;

    static int count;

public:
    StringCustom();                          // 80 (delegate)
    StringCustom(int size);                  // main constructor
    StringCustom(const char* input);         // delegate
    StringCustom(const StringCustom& other); // delegate

    ~StringCustom();

    void inputString();
    void outputString() const;

    static int getCount();
};