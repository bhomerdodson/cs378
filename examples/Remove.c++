// ----------
// Remove.c++
// ----------

#include <algorithm> // remove, remove_copy
#include <cassert>   // assert
#include <cstring>   // strcmp, strlen, strncmp
#include <iostream>  // cout, endl

char* my_remove_copy1 (const char* b, const char* e, char* x, char v) {
    while (b != e) {
        if (*b != v) {
            *x = *b;
            ++x;}
        ++b;}
    return x;}

template <typename II, typename OI, typename T>
OI my_remove_copy2 (II b, II e, OI x, const T& v) {
    while (b != e) {
        if (*b != v) {
            *x = *b;
            ++x;}
        ++b;}
    return x;}

char* my_remove1 (char* b, char* e, char v) {
    return my_remove_copy1(b, e, b, v);}

template <typename FI, typename T>
FI my_remove2 (FI b, FI e, const T& v) {
    return my_remove_copy2(b, e, b, v);}

int main () {
    using namespace std;
    cout << "Remove.c++" << endl;

    {
    const char a[] = "abCbA";
    const int  s   = strlen(a);
          char x[] = "xxxxx";
    const char* const p = remove_copy(a, a + s, x, 'b');
    assert(strcmp(a, "abCbA") == 0);
    assert(strcmp(x, "aCAxx") == 0);
    assert(p - x == 3);
    assert(!strncmp(x, "aCA", 3));
    }

    {
    const char a[] = "abCbA";
    const int  s   = strlen(a);
          char x[] = "xxxxx";
    const char* const p = my_remove_copy1(a, a + s, x, 'b');
    assert(strcmp(a, "abCbA") == 0);
    assert(strcmp(x, "aCAxx") == 0);
    assert(p - x == 3);
    assert(!strncmp(x, "aCA", 3));
    }

    {
    const char a[] = "abCbA";
    const int  s   = strlen(a);
          char x[] = "xxxxx";
    const char* const p = my_remove_copy2(a, a + s, x, 'b');
    assert(strcmp(a, "abCbA") == 0);
    assert(strcmp(x, "aCAxx") == 0);
    assert(p - x == 3);
    assert(!strncmp(x, "aCA", 3));
    }

    {
          char        a[] = "abCbA";
    const int         s   = strlen(a);
    const char* const p   = remove(a, a + s, 'b');
    assert(strcmp(a, "aCAbA") == 0);
    assert(p - a == 3);
    assert(!strncmp(a, "aCA", 3));
    }

    {
          char        a[] = "abCbA";
    const int         s   = strlen(a);
    const char* const p   = my_remove1(a, a + s, 'b');
    assert(strcmp(a, "aCAbA") == 0);
    assert(p - a == 3);
    assert(!strncmp(a, "aCA", 3));
    }

    {
          char        a[] = "abCbA";
    const int         s   = strlen(a);
    const char* const p   = my_remove2(a, a + s, 'b');
    assert(strcmp(a, "aCAbA") == 0);
    assert(p - a == 3);
    assert(!strncmp(a, "aCA", 3));
    }

    return 0;}
