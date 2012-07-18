/*
CS378: Quiz #16 (9 pts)
*/

/* -----------------------------------------------------------------------
1. What is a "hallway usability test"?
   [The Joel Test]
   (1 pt)

A hallway usability test is where you grab the next person that passes by
in the hallway and force them to try to use the code you just wrote. If
you do this to five people, you will learn 95% of what there is to learn
about usability problems in your code.
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (8 pts)

true
true
true
false
*/

#include <iostream> // boolalpha, cout, endl
#include <set>      // set
#include <utility>  // pair

int main () {
    using namespace std;
    cout << boolalpha;

    set<int> x;

    pair<set<int>::iterator, bool> p = x.insert(2);
    cout << (p.first == x.begin()) << endl;
    cout << p.second               << endl;

    pair<set<int>::iterator, bool> q = x.insert(2);
    cout << (q.first == x.begin()) << endl;
    cout << q.second               << endl;

    return 0;}
