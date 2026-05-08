#include "StringCustom.h"

int StringCustom::count = 0;

// основний конструктор
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

// делегування
StringCustom::StringCustom() : StringCustom(80) {}

// безпечне копіювання
void StringCustom::safeCopy(const char* input) {

    delete[] this->str;

    if (!input) {
        this->str = nullptr;
        this->len = 0;
        return;
    }

    this->len = strlen(input);

    this->str = new char[this->len + 1];

    strcpy_s(this->str, this->len + 1, input);
}

// конструктор з рядка
StringCustom::StringCustom(const char* input) : StringCustom(input ? strlen(input) : 0) {
    safeCopy(input);
}

// конструктор копіювання
StringCustom::StringCustom(const StringCustom& other) : StringCustom(other.str) {}

// move-конструктор
StringCustom::StringCustom(StringCustom&& other) noexcept {

    this->str = other.str;
    this->len = other.len;

    other.str = nullptr;
    other.len = 0;

    count++;
}

// деструктор
StringCustom::~StringCustom() {
    delete[] this->str;
    count--;
}

// оператор копіювання
StringCustom& StringCustom::operator=(const StringCustom& other) {

    if (this == &other)
        return *this;

    safeCopy(other.str);

    return *this;
}

// move-оператор
StringCustom& StringCustom::operator=(StringCustom&& other) noexcept {

    if (this == &other)
        return *this;

    delete[] this->str;

    this->str = other.str;
    this->len = other.len;

    other.str = nullptr;
    other.len = 0;

    return *this;
}

// оператор перетину рядків
StringCustom StringCustom::operator*(const StringCustom& other) const {

    if (!this->str || !other.str) {
        return StringCustom(0);
    }

    char* buffer = new char[this->len + 1];

    int index = 0;

    for (int i = 0; i < this->len; i++) {

        char c = this->str[i];
        bool found = false;

        // пошук символу у другому рядку
        for (int j = 0; j < other.len; j++) {

            if (c == other.str[j]) {
                found = true;
                break;
            }
        }

        if (found) {

            // перевірка на повтори
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

// введення рядка
void StringCustom::inputString() {

    cout << "Enter string: ";

    char buffer[1024];

    cin.getline(buffer, 1024);

    safeCopy(buffer);
}

// виведення рядка
void StringCustom::outputString() const {

    if (this->str)
        cout << this->str << endl;
    else
        cout << "(empty)" << endl;
}

// кількість об’єктів
int StringCustom::getCount() {
    return count;
}

// оператор доступу за індексом
char err = '0'; // немає поки можливості обробляти помилки, але треба повертати посилання на щось існуюче...
char& StringCustom::operator[](int index) {

    if (!this->str || index < 0 || index >= this->len) {
        return err;
    }
    return this->str[index];
}

// оператор пошуку символу
int StringCustom::operator()(char symbol) const {

    if (!this->str)
        return -1;

    for (int i = 0; i < this->len; i++) {

        if (this->str[i] == symbol)
            return i;
    }
    return -1;
}

// перетворення в int (довжина рядка)
StringCustom::operator int() const {

    return this->len;
}