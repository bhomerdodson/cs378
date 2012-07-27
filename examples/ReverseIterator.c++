// -------------------
// ReverseIterator.c++
// -------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // iterator, iterator_traits, reverse_iterator
#include <string>    // string
#include <utility>   // !=, <=, >, >=

using namespace std::rel_ops;

template <typename BI>
class my_reverse_iterator {
    public:
        typedef typename std::iterator_traits<BI>::iterator_category iterator_category;
        typedef typename std::iterator_traits<BI>::value_type        value_type;
        typedef typename std::iterator_traits<BI>::difference_type   difference_type;
        typedef typename std::iterator_traits<BI>::pointer           pointer;
        typedef typename std::iterator_traits<BI>::reference         reference;

    public:
        friend my_reverse_iterator operator + (my_reverse_iterator lhs, difference_type rhs) {
            return lhs += rhs;}

        friend my_reverse_iterator operator - (my_reverse_iterator lhs, difference_type rhs) {
            return lhs -= rhs;}

        friend difference_type operator - (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p - lhs._p;}

        friend bool operator == (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p == lhs._p;}

        friend bool operator < (const my_reverse_iterator& lhs, const my_reverse_iterator& rhs) {
            return rhs._p < lhs._p;}

    private:
        BI _p;

    public:
        explicit my_reverse_iterator (BI p = BI()) :
               _p (p)
            {}

        template <typename U>
        explicit my_reverse_iterator (const my_reverse_iterator<U>& that) :
               _p (that._p)
            {}

        // Default copy, destructor, and copy assignment.
        // my_reverse_iterator (const my_reverse_iterator&);
        // ~my_reverse_iterator ();
        // my_reverse_iterator& operator = (const my_reverse_iterator&);

        reference operator * () const {
            BI q = _p;
            return *--q;}

        pointer operator -> () const {
            return &**this;}

        reference operator [] (difference_type d) const {
            return *(*this + d);}

        my_reverse_iterator& operator ++ () {
            --_p;
            return *this;}

        my_reverse_iterator operator ++ (int) {
            my_reverse_iterator x = *this;
            ++(*this);
            return x;}

        my_reverse_iterator& operator -- () {
            ++_p;
            return *this;}

        my_reverse_iterator operator -- (int) {
            my_reverse_iterator x = *this;
            --(*this);
            return x;}

        my_reverse_iterator& operator += (difference_type d) {
            _p -= d;
            return *this;}

        my_reverse_iterator& operator -= (difference_type d) {
            _p += d;
            return *this;}

        BI base () const {
            return _p;}};

int main () {
    using namespace std;
    cout << "ReverseIterator.c++" << endl;

    {
    const string s = "Cba";
          string t = "xxxbA";
    copy(
        reverse_iterator<string::const_iterator>(s.end()),
        reverse_iterator<string::const_iterator>(s.begin()),
        t.begin());
    assert(t == "abCbA");
    }

    {
    const string s = "Cba";
          string t = "xxxbA";
    copy(
        my_reverse_iterator<string::const_iterator>(s.end()),
        my_reverse_iterator<string::const_iterator>(s.begin()),
        t.begin());
    assert(t == "abCbA");
    }

    {
    const string s = "Cba";
          string t = "xxxbA";
    copy(s.rbegin(), s.rend(), t.begin());
    assert(t == "abCbA");
    }

    {
    const string s = "Cba";
          string t = "xxxbA";
    string::const_reverse_iterator b = s.rbegin();
    string::const_reverse_iterator e = s.rend();
    copy(b, e, t.begin());
    assert(t == "abCbA");
    }

    cout << "Done." << endl;
    return 0;}
