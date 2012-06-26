// ------------------
// Initialization.c++
// ------------------

/*
% g++-4.5 -pedantic -std=c++0x -Wall Initialization.c++ -o Initialization.c++.app
% Initialization.c++.app
*/

#include <cassert>
#include <iostream>

struct A {
    int _i;
//  int _i = 2;

    A (int i) :
        _i (i) {}

    A (int i, int j) :
        _i {i + j} {}};

int main () {
    using namespace std;
    cout << "Initialization.c++" << endl;

    int i = 2;
    assert(i == 2);

    int j(3);
    assert(j == 3);

    int k = {4};
    assert(k == 4);

    int a[] = {2, 3, 4};
    assert(a[1] == 3);

    int* b = new int[3]{2, 3, 4};
    assert(b[1] == 3);
    delete [] b;

    A x;
    A y(2);
    A z = 2;
    A t{2};

    cout << "Done." << endl;
    return 0;}
