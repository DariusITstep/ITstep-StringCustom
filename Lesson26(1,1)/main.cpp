#include "StringCustom.h"
#include <iostream>

using namespace std;

int main() {

    StringCustom s1("Windows");
    StringCustom s2("Linux");

    cout << "String 1: ";
    s1.outputString();

    cout << "String 2: ";
    s2.outputString();

    StringCustom result = s1 * s2;

    cout << "Intersection: ";
    result.outputString();

    // перевірка копіювання
    StringCustom copy(s1);

    cout << "Copy with s1: ";
    copy.outputString();

    // перевірка move
    StringCustom moved(std::move(s2));

    cout << "Moved with s2: ";
    moved.outputString();
    
    StringCustom s3("MAC-OS");
    cout << "s3: ";
    s3.outputString();
    // елемент за індексом
    cout << "Element by index 1(s3): " << s3[1] << endl;

    // пошук символа і повернення індексу
    cout << "Sumbol C, index(s3):  " << s3('C') << endl;

    // довжина рядка
    cout << "Len(s3): " << ((int)s3) << endl;

    cout << "Objects: " << StringCustom::getCount() << endl;

    return 0;
}