# matrixlib_braincorps
This is a simple implementation of a matrix library


matrix library
========

This is a simple matrix library implementation. Currently only supports matrix multiplication and transpose
## Example:

```
#include <matrixlib.hpp>
#include <vector>

int main() {

//creates a matrix
MyMatrix<int> A(5,5,1);

std::cout << A;

MyMatrix<int> B = ~A; // transpose

std::cout << B;

MyMatrix<int> C = A*B ;

std::cout << C;

  return 0;
}
```

##compile the program

g++ -I "address to include files" -o myprog myprog.cpp -L "address to linking library (/usr/lib)" -lmatrixlib

## Obtaining matrixlib 

The matrix library is distributed in source form.  It can be
downloaded from the 
[matrixlibrary github repository](https://github.com/kushalsahare/matrixlib_braincorps).
Configuration is via cmake.  On linux the library is downloaded,
configured, built, and installed with the following commands:

```
git clone https://github.com/kushalsahare/matrixlib_braincorps
cd matrixlib_braincorps
mkdir build
cd build
cmake ..
make -j4
sudo make install
```

## Overview of the source code

- [include](include): Public API of the matrix library
- [examples](examples): Some examples.
- [tests](tests): Tests for matrixlibrary.
- [src](src): Implementation files of the library.






