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

    x.push_back(2);
    cout << x.size() << endl;

    x.erase(x.end() + 10);
    cout << x.size() << endl;

    cout << "Done." << endl;
    return 0;}
