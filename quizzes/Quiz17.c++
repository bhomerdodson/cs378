/*
CS378: Quiz #17 (9 pts)
*/

#include <iostream> // boolalpha, cout, endl
#include <map>      // map
#include <utility>  // pair
#include <vector>   // vector

using namespace std;

/* -----------------------------------------------------------------------
1. What is the output of the following function?
   (3 pts) 13 / 26

true false
*/

void test_map_1 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    pair<iterator, bool> q = x.insert(value_type(2, 4));
    cout << (q.first == x.begin()) << " ";
    cout << (x[2]    == 4)         << endl;}

/* -----------------------------------------------------------------------
2. What is the output of the following function?
   (3 pts) 7 / 26

true false
*/

void test_map_2 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type                  x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    cout << (x[4]     == 0) << " ";
    cout << (x.size() == 1) << endl;}

/* -----------------------------------------------------------------------
3. Which of the following is the LEAST expensive well-defined
   implementation of map_reduce()?
   (3 pts) 12 / 26

d.
*/

template <typename II, typename T, typename UF, typename BF>
T map_reduce_a (II b, II e, T v, UF f, BF g) {
    vector<T> x;
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_b (II b, II e, T v, UF f, BF g) {
    vector<T> x;
    x.reserve(distance(b, e));
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_c (II b, II e, T v, UF f, BF g) {
    vector<T> x(b, e);
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_d (II b, II e, T v, UF f, BF g) {
    vector<T> x(distance(b, e));
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

int main () {
    cout << boolalpha;
    test_map_1();
    test_map_2();
    return 0;}
