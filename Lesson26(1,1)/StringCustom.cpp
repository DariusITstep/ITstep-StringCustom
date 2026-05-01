#include "StringCustom.h"

int StringCustom::count = 0;

StringCustom::StringCustom(int size) {

    if (size <= 0) {
        this->str = nullptr;
        this->len = 0;
    }
    else {
        this->len = size;
        this->str = new char[this->len + 1];
        this->str[0] = '\0';
    }

    count++;
}

StringCustom::StringCustom() : StringCustom(80) {}

void StringCustom::safeCopy(const char* input) {

    if (!input) {
        delete[] this->str;
        this->str = nullptr;
        this->len = 0;
        return;
    }

    delete[] this->str;

    this->len = strlen(input);
    this->str = new char[this->len + 1];

    strcpy_s(this->str, this->len + 1, input);
}

StringCustom::StringCustom(const char* input) : StringCustom(input ? strlen(input) : 0) {
    safeCopy(input);
}

StringCustom::StringCustom(const StringCustom& other) : StringCustom(other.len) {
    safeCopy(other.str);
}

StringCustom::~StringCustom() {
    delete[] this->str;
    count--;
}

void StringCustom::inputString() {

    cout << "Enter string: ";

    char buffer[1024];
    cin.getline(buffer, 1024);

    safeCopy(buffer);
}

void StringCustom::outputString() const {

    if (this->str)
        cout << this->str << endl;
    else
        cout << "(empty)" << endl;
}

int StringCustom::getCount() {
    return count;
}

// ----------------------
// оператор перетину * , беру символ першого рядка і шукаю його в другому, якщо є то додаю в результат, перевіряю дублі
// ----------------------
StringCustom StringCustom::operator*(const StringCustom& other) const {

    if (!this->str || !other.str) {
        return StringCustom(0);
    }

    char* buffer = new char[this->len + 1];
    int index = 0;

    for (int i = 0; i < this->len; i++) {

        char c = this->str[i];
        bool found = false;

        for (int j = 0; j < other.len; j++) {
            if (c == other.str[j]) {
                found = true;
                break;
            }
        }

        if (found) {

            bool exists = false;
            for (int k = 0; k < index; k++) {
                if (buffer[k] == c) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                buffer[index++] = c;
            }
        }
    }

    buffer[index] = '\0';

    StringCustom result(buffer);

    delete[] buffer;

    return result;
}