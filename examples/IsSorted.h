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
        if (*p > *b)
            return false;
        ++p;
        ++b;}
    return true;}

#endif // IsSorted_h
