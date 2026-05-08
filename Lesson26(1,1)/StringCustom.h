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
    StringCustom(StringCustom&& other) noexcept;

    ~StringCustom();

    StringCustom& operator=(const StringCustom& other);
    StringCustom& operator=(StringCustom&& other) noexcept;

    StringCustom operator*(const StringCustom& other) const;

    char& operator[](int index);
    int operator()(char symbol) const;
    operator int() const;

    void inputString();
    void outputString() const;

    static int getCount();
};