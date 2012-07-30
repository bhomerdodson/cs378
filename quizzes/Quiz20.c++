/*
CS378: Quiz #20 (9 pts)
*/

#include <algorithm> // set_intersection
#include <iostream>  // cout, endl

using namespace std;

/* -----------------------------------------------------------------------
1. The algorithm std::reverse() is explicitly defined for which two
   kinds of iterators?
   (3 pts)

BI and RI
*/

/* -----------------------------------------------------------------------
2. The algorithm std::distance() is explicitly defined for which two
   kinds of iterators?
   (3 pts)

II and RI
*/

/* -----------------------------------------------------------------------
3. What is the output of the following program?
   (3 pts)

6 7 10
*/

int main () {
    const int a[] = {2, 4, 4, 6, 6, 7, 8, 10};
    const int b[] = {3, 5, 5, 6, 7, 7, 9, 10};

    const int s = sizeof(a) / sizeof(a[0]);

    int        x[s];
    int* const q = set_intersection(a, a + s, b, b + s, x);
    int*       p = x;
    while (p != q) {
        cout << *p << " ";
        ++p;}
    cout << endl;

    return 0;}
