// -----------
// Example.c++
// -----------

#include <algorithm> // max
#include <cassert>   // assert
#include <iostream>  // cout, endl

struct A {
    friend bool operator < (const A& lhs, const A& rhs) {
        return lhs._n < rhs._n;}

    int _n;

    A (int n) :
            _n (n)
        {}};

struct B {
    friend bool operator < (const B& lhs, const B& rhs) {
        return lhs._n < rhs._n;}

    int _n;

    B (int n) :
            _n (n)
        {}};

template <typename T>
const T& my_max (const T& x, const T& y) {
    if (x < y)
        return y;
    return x;}

int main () {
    using namespace std;
    cout << "Example.c++" << endl;

    {
    A x = 2;
    A y = 3;
    assert(&   max(x, y) == &y);
    assert(&my_max(x, y) == &y);
    }

    {
    B x = 2;
    B y = 3;
    assert(&   max(x, y) == &y);
    assert(&my_max(x, y) == &y);
    }

    cout << "Done." << endl;
    return 0;}
