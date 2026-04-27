#include "StringCustom.h"
#include <iostream>

int main() {

    StringCustom a;              // 80
    a.inputString();
    a.outputString();

    StringCustom b(50);
    b.inputString();
    b.outputString();

    StringCustom c("Hello world");
    c.outputString();

    StringCustom d(c);
    d.outputString();

    StringCustom e(0);          // nullptr empty
    e.outputString();

    cout << "Objects: " << StringCustom::getCount() << endl;

    return 0;
}