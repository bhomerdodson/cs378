// ----------
// Tuples.c++
// ----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // pair

#include "boost/tuple/tuple.hpp" // tie, tuple

template <typename T0, typename T1>
struct my_tuple {
    T0 first;
    T1 second;

    my_tuple (T0 first, T1 second) :
            first  (first),
            second (second)
        {}};

template <typename T0, typename T1>
my_tuple<T0&, T1&> my_tie (T0 first, T1 second) {
    return my_tuple<T0&, T1&>(first, second);}

int main () {
    using namespace std;
    using namespace boost;
    cout << "Tuples.c++" << endl;

    typedef    tuple<int&, int&>    tuple_type;
    typedef my_tuple<int&, int&> my_tuple_type;

    int v1 = 2;
    int v2 = 3;

    {
    const tuple_type x(v1, v2);
    assert(&x.get<0>() == &v1);
    assert(&x.get<1>() == &v2);
    }

    {
    const my_tuple_type x(v1, v2);
    assert(&x.first  == &v1);
    assert(&x.second == &v2);
    }

    {
    const tuple_type x(v1, v2);
    const tuple_type y = x;
    assert(&y.get<0>() == &v1);
    assert(&y.get<1>() == &v2);
    }

    {
    const my_tuple_type x(v1, v2);
    const my_tuple_type y = x;
    assert(&y.first  == &v1);
    assert(&y.second == &v2);
    }

    {
    assert(&tie(v1, v2).get<0>() == &v1);
    assert(&tie(v1, v2).get<1>() == &v2);
    }

    {
    assert(&my_tie(v1, v2).first  == &v1);
    assert(&my_tie(v1, v2).second == &v2);
    }

    {
    int i = 2;
    int j = 3;
    tie(i, j) = make_pair(4, 5);
    assert(i == 4);
    assert(j == 5);
    }

    cout << "Done." << endl;
    return 0;}
