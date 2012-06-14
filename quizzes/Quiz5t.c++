/*
CS378: Quiz #5 (9 pts)
*/

1. In C++, list FOUR things that you can do wrong with manual memory
   management.
   (4 pts)

2. Why is a memory checker like Valgrind only of limited use even if
   perfect?
   (3 pts)

3. Which operations are being invoked in the following line:
   (2 pts)

#include <cassert>
#include <iostream>
#include <string>

int main () {
    using namespace std;
    string s = "abc";
    assert(s == "abc");       // this line
    cout << "Done." << endl;}
