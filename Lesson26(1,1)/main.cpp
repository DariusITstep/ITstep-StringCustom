#include "StringCustom.h"
#include <iostream>

using namespace std;

int main() {

    StringCustom a;
    a.inputString();
    a.outputString();

    StringCustom b(50);
    b.inputString();
    b.outputString();

    StringCustom c("Hello world");
    c.outputString();

    StringCustom d(c);
    d.outputString();

    StringCustom e(0);
    e.outputString();

    cout << "Objects: " << StringCustom::getCount() << endl;

    return 0;
}