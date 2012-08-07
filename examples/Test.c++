// --------------
// FunctionsX.c++
// --------------

/*
% g++-4.7 -pedantic -std=c++11 -Wall FunctionsX.c++ -o FunctionsX.c++.app
% FunctionsX.c++.app
*/

#include <cassert>    // assert
#include <functional> // function, multiplies, plus
#include <iostream>   // cout, endl

int plus_1 (int x, int y) {
    return x + y;}

int multiplies_1 (int x, int y) {
    return x * y;}

template <typename T>
T plus_2 (T x, T y) {
    return x + y;}

template <typename T>
T multiplies_2 (T x, T y) {
    return x * y;}

struct plus_3 {
    int operator () (int x, int y) const {
        return x + y;}};

struct multiplies_3 {
    int operator () (int x, int y) const {
        return x * y;}};

template <typename T>
struct plus_4 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
struct multiplies_4 {
    T operator () (const T& x, const T& y) const {
        return x * y;}};

int f (int (*bf) (int, int), int x, int y, int z) {
    assert(bf == *bf);
    return bf(bf(x, y), z);}

template <typename BF, typename T>
T g (BF bf, const T& x, const T& y, const T& z) {
    return bf(bf(x, y), z);}

int h (std::function<int (int, int)> bf, int x, int y, int z) {
    return bf(bf(x, y), z);}

int main () {
    using namespace std;
    cout << "FunctionsX.c++" << endl;

    assert(plus_1      (2, 3) == 5);
    assert(multiplies_1(2, 3) == 6);

    assert(plus_2      (2, 3) == 5);
    assert(multiplies_2(2, 3) == 6);

    assert(plus_3()      (2, 3) == 5);
    assert(multiplies_3()(2, 3) == 6);

    assert(plus_4<int>()      (2, 3) == 5);
    assert(multiplies_4<int>()(2, 3) == 6);

    assert(plus<int>()      (2, 3) == 5);
    assert(multiplies<int>()(2, 3) == 6);

    assert([](int x, int y) {return x + y;}(2, 3) == 5);
    assert([](int x, int y) {return x * y;}(2, 3) == 6);



    assert(f( plus_1,       2, 3, 4) ==  9);
    assert(f( multiplies_1, 2, 3, 4) == 24);
    assert(f(&plus_1,       2, 3, 4) ==  9);
    assert(f(&multiplies_1, 2, 3, 4) == 24);

    assert(f( plus_2,       2, 3, 4) ==  9);
    assert(f( multiplies_2, 2, 3, 4) == 24);
    assert(f(&plus_2,       2, 3, 4) ==  9);
    assert(f(&multiplies_2, 2, 3, 4) == 24);

//  assert(f(plus_3(),       2, 3, 4) ==  9); // error: cannot convert ‘plus_3’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’
//  assert(f(multiplies_3(), 2, 3, 4) == 24); // error: cannot convert ‘multiplies_3’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’

//  assert(f(plus_4<int>(),       2, 3, 4) ==  9); // error: cannot convert ‘plus_4<int>’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’
//  assert(f(multiplies_4<int>(), 2, 3, 4) == 24); // error: cannot convert ‘multiplies_4<int>’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’

//  assert(f(plus<int>(),       2, 3, 4) ==  9); // error: cannot convert ‘plus<int>’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’
//  assert(f(multiplies<int>(), 2, 3, 4) == 24); // error: cannot convert ‘multiplies<int>’ to ‘int (*)(int, int)’ for argument ‘1’ to ‘int f(int (*)(int, int), int, int, int)’

    assert(f([](int x, int y) {return x + y;}, 2, 3, 4) ==  9);
    assert(f([](int x, int y) {return x * y;}, 2, 3, 4) == 24);



    assert(g( plus_1,       2, 3, 4) ==  9);
    assert(g( multiplies_1, 2, 3, 4) == 24);
    assert(g(&plus_1,       2, 3, 4) ==  9);
    assert(g(&multiplies_1, 2, 3, 4) == 24);

    assert(g( plus_2<int>,       2, 3, 4) ==  9);
    assert(g( multiplies_2<int>, 2, 3, 4) == 24);
    assert(g(&plus_2<int>,       2, 3, 4) ==  9);
    assert(g(&multiplies_2<int>, 2, 3, 4) == 24);

    assert(g(plus_3(),       2, 3, 4) ==  9);
    assert(g(multiplies_3(), 2, 3, 4) == 24);

    assert(g(plus_4<int>(),       2, 3, 4) ==  9);
    assert(g(multiplies_4<int>(), 2, 3, 4) == 24);

    assert(g(plus<int>(),       2, 3, 4) ==  9);
    assert(g(multiplies<int>(), 2, 3, 4) == 24);

    assert(g([](int x, int y) {return x + y;}, 2, 3, 4) ==  9);
    assert(g([](int x, int y) {return x * y;}, 2, 3, 4) == 24);



    assert(h( plus_1,       2, 3, 4) ==  9);
    assert(h( multiplies_1, 2, 3, 4) == 24);
    assert(h(&plus_1,       2, 3, 4) ==  9);
    assert(h(&multiplies_1, 2, 3, 4) == 24);

    assert(h( plus_2<int>,       2, 3, 4) ==  9);
    assert(h( multiplies_2<int>, 2, 3, 4) == 24);
    assert(h(&plus_2<int>,       2, 3, 4) ==  9);
    assert(h(&multiplies_2<int>, 2, 3, 4) == 24);

    assert(h(plus_3(),       2, 3, 4) ==  9);
    assert(h(multiplies_3(), 2, 3, 4) == 24);

    assert(h(plus_4<int>(),       2, 3, 4) ==  9);
    assert(h(multiplies_4<int>(), 2, 3, 4) == 24);

    assert(h(plus<int>(),       2, 3, 4) ==  9);
    assert(h(multiplies<int>(), 2, 3, 4) == 24);

    assert(h([](int x, int y) {return x + y;}, 2, 3, 4) ==  9);
    assert(h([](int x, int y) {return x * y;}, 2, 3, 4) == 24);

    cout << "Done." << endl;
    return 0;}
