#ifndef MATRIXLIB_H_
#define MATRIXLIB_H_

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>

//namespace BC_LIB{

template <class T>

class MyMatrix {

    std::vector<T> elements_ ; // array of elements

    const unsigned rows_;
    const unsigned cols_; 

    public:

    //constructor
    MyMatrix (); // default
    MyMatrix (const unsigned int rows, const unsigned int cols, const T* elements=0);
    MyMatrix (const MyMatrix<T>&);

    //destructor
    ~MyMatrix();

    //operator overloading

    MyMatrix<T> operator=(const MyMatrix<T>& ) const;
    MyMatrix<T> operator+(const MyMatrix<T>& ) const;
    MyMatrix<T> operator*(const MyMatrix<T>& ) const;
    MyMatrix<T> operator-(const MyMatrix<T>& ) const;
    MyMatrix<T> operator~() const ;
    //functions

    MyMatrix<T> transpose() const;

    //MyMatrix<T>

};

//} //namespace matrixlib_braincorps

#endif // MATRIXLIB_H_

