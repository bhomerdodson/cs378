// --------------
// FunctionsX.c++
// --------------

/*
% g++-4.5 -pedantic -std=c++0x -Wall FunctionsX.c++ -o FunctionsX.c++.app
% FunctionsX.c++.app
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

int f (int (*bf) (int, int), int x, int y, int z) {
    assert(bf == *bf);
    return bf(bf(x, y), z);}

template <typename BF, typename T>
T g (BF bf, const T& x, const T& y, const T& z) {
    return bf(bf(x, y), z);}

int main () {
    using namespace std;
    cout << "FunctionsX.c++" << endl;

    assert([](int x, int y) {return x + y;}(2, 3) == 5);
    assert([](int x, int y) {return x * y;}(2, 3) == 6);

    assert(f([](int x, int y) {return x + y;}, 2, 3, 4) ==  9);
    assert(f([](int x, int y) {return x * y;}, 2, 3, 4) == 24);

    assert(g([](int x, int y) {return x + y;}, 2, 3, 4) ==  9);
    assert(g([](int x, int y) {return x * y;}, 2, 3, 4) == 24);

    cout << "Done." << endl;
    return 0;}
