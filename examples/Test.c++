#include <cassert>
#include <iostream>

template <typename T>
struct A {
    friend bool operator == (const A&, const A&) {
        return true;}

    A (const T&)
        {}};

template <typename T>
struct B {
    B (const T&)
        {}};

template <typename T>
bool operator == (const B<T>&, const B<T>&) {
    return true;}

int main () {
    using namespace std;
    cout << "Test.c++" << endl;

    {
    A<int> x(2);
    assert(x == 2);
    }

    {
    B<int> x(2);
//  assert(x == 2); // error: no match for ‘operator==’ in ‘x == 2’
    }

    cout << "Done." << endl;
    return 0;}
