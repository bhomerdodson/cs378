/*
CS378: Quiz #19 (9 pts)
*/

/* -----------------------------------------------------------------------
1. What are the five iterator-category tags?
   And what are their inheritance relationships.
   (4 pts)

IIT
OIT
FIT : IIT
BIT : FIT
RIT : BIT
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (5 pts)

f(std::random_access_iterator_tag)
f(std::random_access_iterator_tag)
f(std::bidirectional_iterator_tag)
f(std::bidirectional_iterator_tag)
f(std::bidirectional_iterator_tag)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <iterator> // bidirectional_iterator_tag iterator_traits
                    // random_access_iterator_tag
#include <list>     // list
#include <map>      // map
#include <set>      // set
#include <vector>   // vector

using namespace std;

void f (std::bidirectional_iterator_tag) {
    std::cout << "f(std::bidirectional_iterator_tag)" << std::endl;}

void f (std::random_access_iterator_tag) {
    std::cout << "f(std::random_access_iterator_tag)" << std::endl;}

int main () {
    using namespace std;

    f(iterator_traits<                   int*>::iterator_category());
    f(iterator_traits<  vector<int>::iterator>::iterator_category());
    f(iterator_traits<    list<int>::iterator>::iterator_category());
    f(iterator_traits<     set<int>::iterator>::iterator_category());
    f(iterator_traits<map<int, int>::iterator>::iterator_category());

    return 0;}
