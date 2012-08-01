// -----------------
// SetDifference.c++
// -----------------

#include <algorithm> // copy, equal, set_difference
#include <cassert>   // assert
#include <iostream>  // cout, endl

#include "IsSorted.h"

template <typename II1, typename II2, typename OI>
OI my_set_difference (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    assert(issorted(b1, e1));
    assert(issorted(b2, e2));
    while ((b1 != e1) && (b2 != e2)) {
        if (*b1 < *b2) {
            *x = *b1;
            ++b1;
            ++x;}
        else if (*b2 < *b1)
            ++b2;
        else {
            ++b1;
            ++b2;}}
    return std::copy(b1, e1, x);}

int main () {
    using namespace std;
    cout << "SetDifference.c++" << endl;

    const int a[] = {2, 4, 4, 6, 7, 7, 8, 9, 9};
    const int b[] = {3, 5, 5, 6, 7, 7, 8, 8, 9};
    const int c[] = {2, 4, 4, 9};

    const int s = sizeof(a) / sizeof(a[0]);
    const int t = sizeof(b) / sizeof(b[0]);
    const int u = sizeof(c) / sizeof(c[0]);

    {
    int x[u];
    set_difference(a, a + s, b, b + t, x);
    assert(issorted(x, x + u));
    assert(equal(x, x + u, c));
    }

    {
    int x[u];
    my_set_difference(a, a + s, b, b + t, x);
    assert(issorted(x, x + u));
    assert(equal(x, x + u, c));
    }

    cout << "Done." << endl;
    return 0;}
