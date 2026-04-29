#include "StringCustom.h"

int StringCustom::count = 0;

// основний
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

// за замовченням
StringCustom::StringCustom() : StringCustom(80) {}

// безпечне копіювання
void StringCustom::safeCopy(const char* input) {

    if (!input) {
        this->str = nullptr;
        this->len = 0;
        return;
    }

    delete[] this->str;

    this->len = strlen(input);
    this->str = new char[this->len + 1];

    strcpy_s(this->str, this->len + 1, input);
}

// с-стиль
StringCustom::StringCustom(const char* input) : StringCustom(input ? strlen(input) : 0) {
    safeCopy(input);
}

// ксерокс
StringCustom::StringCustom(const StringCustom& other) : StringCustom(other.len) {
    safeCopy(other.str);
}

// деструктор
StringCustom::~StringCustom() {
    delete[] this->str;
    count--;
}

// ввід рядка
void StringCustom::inputString() {

    cout << "Enter string: ";

    char buffer[1024];
    cin.getline(buffer, 1024);

    safeCopy(buffer);
}

// вивід рядка
void StringCustom::outputString() const {

    if (this->str)
        cout << this->str << endl;
    else
        cout << "(empty)" << endl;
}

// кількість створених о'єктів
int StringCustom::getCount() {
    return count;
}