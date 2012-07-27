// ----------
// Remove.c++
// ----------

#include <algorithm> // remove, remove_copy
#include <cassert>   // assert
#include <cstring>   // strcmp, strlen, strncmp
#include <iostream>  // cout, endl

char* my_remove1 (char* b, char* e, char v) {
    char* x = b;
    while (b != e) {
        if (*b != v) {
            *x = *b;
            ++x;}
        ++b;}
    return x;}

template <typename FI, typename T>
FI my_remove2 (FI b, FI e, const T& v) {
    FI x = b;
    while (b != e) {
        if (*b != v) {
            *x = *b;
            ++x;}
        ++b;}
    return x;}

int main () {
    using namespace std;
    cout << "Remove.c++" << endl;

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
