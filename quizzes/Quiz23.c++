/*
CS378: Quiz #23 (9 pts)
*/

/* -----------------------------------------------------------------------
1. What is the WEAKEST possible iterator that std::reverse_iterator<>()
   needs?
   (4 pts)

bidirectional
*/

/* -----------------------------------------------------------------------
2. What do you think the following declares? It is legal.
   (1 pt)

a function, named x, that takes an int, named v, and returns an int
*/

int x (int (v));

/* -----------------------------------------------------------------------
3. What do you think the following declares? It is legal.
   (1 pt)

a function, named y, that takes an unnamed function and returns an int
the unnamed function takes no arguments and returns an int
*/

int y (int ());

/* -----------------------------------------------------------------------
4. What do you think the following declares? It is legal.
   (3 pts)

a vector<char>, named v, size 3, initialized with 'x's

a string, named z, constructed with the beginning and end of the vector

a function, named t, that takes two arguments
the first argument is an istream_iterator<char>, named cin
the second argument is an unnamed function
the unnamed function takes no arguments and returns an
istream_iterator<char>
*/

#include <iostream> // cin
#include <iterator> // istream_iterator
#include <string>   // string
#include <vector>   // vector

using namespace std;

vector<char> v(3, 'x');

string z(v.begin(),                   v.end());

string t(istream_iterator<char>(cin), istream_iterator<char>());
