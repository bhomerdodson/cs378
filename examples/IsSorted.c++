// ------------
// IsSorted.c++
// ------------

#include <algorithm>  // sort
#include <functional> // greater
#include <iostream>   // cout, endl
#include <cassert>    // assert
#include <cstdlib>    // rand

#include "IsSorted.h"

template <typename FI>
void random_fill (FI b, FI e) {
    while (b != e) {
        *b = std::rand();
        ++b;}}

int main () {
    using namespace std;
    cout << "IsSorted.c++" << endl;

    {
    int a[] = {2, 3, 4, 1};
    assert( issorted(a, a));
    assert( issorted(a, a + 1));
    assert( issorted(a, a + 2));
    assert( issorted(a, a + 3));
    assert(!issorted(a, a + 4));
    }

    for (int i = 0; i < 10; ++i) {
        const int s = 1000;
              int a[s];
        random_fill(a, a + s);
        assert(!issorted(a, a + s));
        sort(a, a + s);
        assert( issorted(a, a + s));}

    {
    int a[] = {4, 3, 2, 5};
    assert( issorted(a, a,     greater<int>()));
    assert( issorted(a, a + 1, greater<int>()));
    assert( issorted(a, a + 2, greater<int>()));
    assert( issorted(a, a + 3, greater<int>()));
    assert(!issorted(a, a + 4, greater<int>()));
    }

    for (int i = 0; i < 10; ++i) {
        const int s = 1000;
              int a[s];
        random_fill(a, a + s);
        assert(!issorted(a, a + s, greater<int>()));
        sort(a, a + s, greater<int>());
        assert( issorted(a, a + s, greater<int>()));}

    cout << "Done." << endl;
    return 0;}
