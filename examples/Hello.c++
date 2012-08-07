// ---------
// Hello.c++
// ---------

/*
% g++ -v
Using built-in specs.
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 4.4.3-4ubuntu5.1' --with-bugurl=file:///usr/share/doc/gcc-4.4/README.Bugs --enable-languages=c,c++,fortran,objc,obj-c++ --prefix=/usr --enable-shared --enable-multiarch --enable-linker-build-id --with-system-zlib --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --with-gxx-include-dir=/usr/include/c++/4.4 --program-suffix=-4.4 --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-plugin --enable-objc-gc --disable-werror --with-arch-32=i486 --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 4.4.3 (Ubuntu 4.4.3-4ubuntu5.1)

% g++-4.7 -v
Using built-in specs.
COLLECT_GCC=g++-4.7
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/4.7/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu/Linaro 4.7.1-3lucid3' --with-bugurl=file:///usr/share/doc/gcc-4.7/README.Bugs --enable-languages=c,c++,go,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-4.7 --enable-shared --enable-linker-build-id --with-system-zlib --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --with-gxx-include-dir=/usr/include/c++/4.7 --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --enable-gnu-unique-object --enable-plugin --enable-objc-gc --disable-werror --with-arch-32=i586 --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 4.7.1 (Ubuntu/Linaro 4.7.1-3lucid3)

% clang -v
Debian clang version 3.1-4ppa3 (branches/release_31) (based on LLVM 3.1)
Target: x86_64-pc-linux-gnu
Thread model: posix



% g++ -pedantic -std=c++0x -Wall Hello.c++ -o Hello.c++.app
% Hello.c++.app
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Nothing to be done." << endl;
    return 0;}
