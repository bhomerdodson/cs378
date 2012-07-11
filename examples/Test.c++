// --------
// Test.c++
// --------

#include <cassert>
#include <iostream>
#include <deque>

int main () {
    using namespace std;
    cout << "Test.c++" << endl;

    deque<int> x;
    cout << x.size() << endl;

    deque<int>::iterator y;

    cout << "Done." << endl;
    return 0;}
