// ------------
// IsSorted.c++
// ------------

#ifndef IsSorted_h
#define IsSorted_h

template <typename II>
bool issorted (II b, II e) {
    if (b == e)
        return true;
    II p = b;
    ++b;
    while (b != e) {
        if (*b < *p)
            return false;
        ++p;
        ++b;}
    return true;}

template <typename II, typename BP>
bool issorted (II b, II e, BP f) {
    if (b == e)
        return true;
    II p = b;
    ++b;
    while (b != e) {
        if (f(*b, *p))
            return false;
        ++p;
        ++b;}
    return true;}

#endif // IsSorted_h
