/*
CS378: Quiz #13 (9 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

A(A) A(A) A(A) A(A) ~A() ~A() ~A()
=(A) =(A) =(A) =(A) A(A)
~A() ~A() ~A() ~A() ~A() ~A() ~A() ~A() ~A() ~A() ~A()
*/

#include <iostream> // cout, endl
#include <vector>   // vector

using namespace std;

struct A {
    A () {
        cout << "A() ";}

    A (const A&) {
        cout << "A(A) ";}

    ~A () {
        cout << "~A() ";}

    A& operator = (const A&) {
        cout << "=(A) ";
        return *this;}};

int main () {
    {
    A v;               // A()
    cout << endl;

    vector<A> x(5, v); // A(A) A(A) A(A) A(A) A(A)
    cout << endl;

    vector<A> y(3, v); // A(A) A(A) A(A)
    cout << endl;

    y.push_back(v);    // (3 pts)
    cout << endl;

    y = x;             // (3 pts)
    cout << endl;

    }                  // (3 pts)
    cout << endl;

    return 0;}
