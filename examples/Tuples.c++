// ----------
// Tuples.c++
// ----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // pair

#include "boost/tuple/tuple.hpp" // tie, tuple

std::pair<int, int> f () {
    return std::make_pair(4, 5);}

int main () {
    using namespace std;
    using namespace boost;
    cout << "Tuples.c++" << endl;

    typedef tuple<int&, int&> tuple_type;

    int v1 = 2;
    int v2 = 3;

    {
    const tuple_type x(v1, v2);
    assert(&x.get<0>() == &v1);
    assert(&x.get<1>() == &v2);
    }

    {
    const tuple_type x(v1, v2);
    const tuple_type y = x;
    assert(&y.get<0>() == &v1);
    assert(&y.get<1>() == &v2);
    }

    {
    assert(&tie(v1, v2).get<0>() == &v1);
    assert(&tie(v1, v2).get<1>() == &v2);
    }

    {
    int i = 2;
    int j = 3;
    tie(i, j) = f();
    assert(i == 4);
    assert(j == 5);
    }

    cout << "Done." << endl;
    return 0;}
