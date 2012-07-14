// -------------
// Factorial.c++
// -------------

#include <cassert>    // assert
#include <functional> // multiplies
#include <iostream>   // cout, endl
#include <numeric>    // accumulate

template <typename T>
class XRange {
    private:
        T _n;

    public:
        explicit XRange (const T& n) :
                _n (n)
            {}

        bool operator == (const XRange& rhs) {
            return _n == rhs._n;}

        bool operator != (const XRange& rhs) {
            return !(*this == rhs);}

        XRange& operator ++ () {
            ++_n;
            return *this;}

        const XRange operator ++ (int) {
            XRange x(*this);
            ++_n;
            return x;}

        const T& operator * () {
            return _n;}};

int factorial_1 (int n) {
    if (n < 2)
        return 1;
    return n * factorial_1(n - 1);}

int factorial_2 (int n) {
    int x = 1;
    while (n > 1) {
        x *= n;
        --n;}
    return x;}

int factorial_3 (int n) {
    return std::accumulate(XRange<int>(1), XRange<int>(n + 1), 1, std::multiplies<int>());}

template <typename F>
void test (F f) {
    assert(f(0) ==   1);
    assert(f(1) ==   1);
    assert(f(2) ==   2);
    assert(f(3) ==   6);
    assert(f(4) ==  24);
    assert(f(5) == 120);}

int main () {
    using namespace std;
    cout << "Factorial.c++" << endl;

    test(factorial_1);
    test(factorial_2);
    test(factorial_3);

    cout << "Done." << endl;
    return 0;}
