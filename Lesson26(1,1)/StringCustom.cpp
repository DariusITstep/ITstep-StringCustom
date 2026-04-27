#include "StringCustom.h"

int StringCustom::count = 0;

// DEFAULT -> delegate
StringCustom::StringCustom() : StringCustom(80) {}

// MAIN CONSTRUCTOR
// nullptr-model supported
StringCustom::StringCustom(int size) {

    if (size <= 0) {
        str = nullptr;
        len = 0;
    }
    else {
        len = size;
        str = new char[len + 1];
        str[0] = '\0';
    }

    count++;
}

// FROM C-STRING -> delegate
StringCustom::StringCustom(const char* input) : StringCustom(input ? strlen(input) : 0) {
    if (input && str) {
        strcpy_s(str, len + 1, input);
    }
}

// COPY -> delegate
StringCustom::StringCustom(const StringCustom& other) : StringCustom(other.len) {
    if (other.str && str) {
        strcpy_s(str, len + 1, other.str);
    }
}

// destructor
StringCustom::~StringCustom() {
    delete[] str;
    count--;
}

// input (safe)
void StringCustom::inputString() {

    cout << "Enter string: ";

    char buffer[1024];
    cin.getline(buffer, 1024);

    delete[] str;

    len = strlen(buffer);

    if (len == 0) {
        str = nullptr;
        return;
    }

    str = new char[len + 1];
    strcpy_s(str, len + 1, buffer);
}

// output
void StringCustom::outputString() const {
    if (str)
        cout << str << endl;
    else
        cout << "(empty)" << endl;
}

// static
int StringCustom::getCount() {
    return count;
}