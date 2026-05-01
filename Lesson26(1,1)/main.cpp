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

    StringCustom c("Hello");
    StringCustom d("World");

    StringCustom result = c * d;
    result.outputString(); 

    StringCustom copy(c);
    copy.outputString();

    StringCustom empty(0);
    empty.outputString();

    cout << "Objects: " << StringCustom::getCount() << endl;

    return 0;
}