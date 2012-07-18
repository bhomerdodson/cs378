// ----------
// Reduce.c++
// ----------

#include <algorithm>  // transform
#include <cassert>    // assert
#include <ctime>      // clock, clock_t, CLOCKS_PER_SEC
#include <functional> // multiplies, plus
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <vector>     // vector

struct sqre {
    int operator () (int x) {
        return x * x;}};

struct cube {
    int operator () (int x) {
        return x * x * x;}};

template <typename II, typename T, typename UF, typename BF>
T map_reduce_1 (II b, II e, T v, UF f, BF g) {
    std::vector<T> x(std::distance(b, e));
    std::transform(b, e, x.begin(), f);
    return std::accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_2 (II b, II e, T v, UF f, BF g) {
    while (b != e) {
        v = g(v, f(*b));
        ++b;}
    return v;}

int main () {
    using namespace std;
    cout << "MapReduce.c++" << endl;

    {
    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);

    assert(map_reduce_1(a, a + s, 0, sqre(), plus<int>())       ==    29);
    assert(map_reduce_1(a, a + s, 0, cube(), plus<int>())       ==    99);
    assert(map_reduce_1(a, a + s, 1, sqre(), multiplies<int>()) ==   576);
    assert(map_reduce_1(a, a + s, 1, cube(), multiplies<int>()) == 13824);

    assert(map_reduce_2(a, a + s, 0, sqre(), plus<int>())       ==    29);
    assert(map_reduce_2(a, a + s, 0, cube(), plus<int>())       ==    99);
    assert(map_reduce_2(a, a + s, 1, sqre(), multiplies<int>()) ==   576);
    assert(map_reduce_2(a, a + s, 1, cube(), multiplies<int>()) == 13824);
    }

    const vector<int> x(1000000, 1);
    cout << endl;

    {
    cout << "map_reduce_1" << endl;
    const clock_t cs = clock();

    cout << map_reduce_1(x.begin(), x.end(), 0, sqre(), plus<int>())       << endl;
    cout << map_reduce_1(x.begin(), x.end(), 0, cube(), plus<int>())       << endl;
    cout << map_reduce_1(x.begin(), x.end(), 1, sqre(), multiplies<int>()) << endl;
    cout << map_reduce_1(x.begin(), x.end(), 1, cube(), multiplies<int>()) << endl;

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    {
    cout << "map_reduce_2" << endl;
    const clock_t cs = clock();

    cout << map_reduce_2(x.begin(), x.end(), 0, sqre(), plus<int>())       << endl;
    cout << map_reduce_2(x.begin(), x.end(), 0, cube(), plus<int>())       << endl;
    cout << map_reduce_2(x.begin(), x.end(), 1, sqre(), multiplies<int>()) << endl;
    cout << map_reduce_2(x.begin(), x.end(), 1, cube(), multiplies<int>()) << endl;

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    cout << "Done." << endl;
    return 0;}

/*
Target: i686-apple-darwin10
gcc version 4.2.1 (Apple Inc. build 5666) (dot 3)

MapReduce.c++

map_reduce_1
1000000
1000000
1
1
153.182 milliseconds

map_reduce_2
1000000
1000000
1
1
74.007 milliseconds

Done.
*/
