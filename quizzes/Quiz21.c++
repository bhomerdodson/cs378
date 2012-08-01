/*
CS378: Quiz #21 (9 pts)
*/

/* -----------------------------------------------------------------------
1. As described in Paper #7: Gender Differences in Computer Science
   Students, which of the following statements was found to be true?
   (2 pts)

a. Gender discrimination is perceived as a significant problem in CS
   departments.

b. Female CS majors had less confidence with computers than did male
   non-majors.

c. Study participants did not view CS as a field in which career
   goals and family life were compatible.

d. A difference in quantitative ability between gender does explain
   some of the gender difference in CS enrollment.

b
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (7 pts)

true
true
abcx
true
true
true
abcxx
*/

#include <iostream> // boolalpha, cout, endl
#include <iterator> // back_insert_iterator, back_inserter
#include <string>   // string

using namespace std;

int main () {
    cout << boolalpha; // bool outputs as true or false

    string                       s = "abc";
    back_insert_iterator<string> p(s);

    cout << (&*p         == &p) << endl;
    cout << (&(*p = 'x') == &p) << endl;
    cout << s << endl;

    cout << (&++p == &p) << endl;

    cout << (&*p         == &p) << endl;
    cout << (&(*p = 'x') == &p) << endl;
    cout << s << endl;

    return 0;}
