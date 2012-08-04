/*
CS378: Quiz #22 (9 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

true
true
a
true
true
true
true
true
ac
*/

#include <iostream> // boolalpha, cout, endl
#include <iterator> // istream_iterator, ostream_iterator
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

using namespace std;

int main () {
    cout << boolalpha; // bool outputs as true or false

    istringstream          x("abc");
    istream_iterator<char> p(x);

    ostringstream          y;
    ostream_iterator<char> q(y);

    cout << (*p == 'a') << endl;

    cout << (&(*q = *p) == &q) << endl;
    cout << y.str() << endl;

    cout << (&++p == &p) << endl;
    cout << (*p == 'b') << endl;

    cout << (&++p == &p) << endl;
    cout << (*p == 'c') << endl;

    cout << (&(*q = *p) == &q) << endl;
    cout << y.str() << endl;

    return 0;}
