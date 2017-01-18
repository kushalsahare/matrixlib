#ifndef MATRIXLIB_H_
#define MATRIXLIB_H_

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>


template <class T>

class MyMatrix {
    
    std::vector<std::vector<T> > mat_;
    unsigned rows_;
    unsigned cols_;
    public:

    //constructor
    
    MyMatrix(unsigned rows, unsigned cols, const T& initial=0);
    MyMatrix(const MyMatrix<T>& rhs);
    virtual ~MyMatrix();

    // Operator overloading, for "standard" mathematical matrix operations                                                                                                                                                          
    MyMatrix<T>& operator=(const MyMatrix<T>& rhs);

    // Matrix mathematical operations                                                                                                                                                                                               
    MyMatrix<T> operator+(const MyMatrix<T>& rhs);
    MyMatrix<T>& operator+=(const MyMatrix<T>& rhs);
    MyMatrix<T> operator-(const MyMatrix<T>& rhs) const;
    MyMatrix<T>& operator-=(const MyMatrix<T>& rhs);
    MyMatrix<T> operator*(const MyMatrix<T>& rhs);
    MyMatrix<T>& operator*=(const MyMatrix<T>& rhs);
    MyMatrix<T> operator~(const 

    MyMatrix<T> transpose() const;

    // Access the individual elements                                                                                                                                                                                               
    T& operator()(const unsigned& row, const unsigned& col);
    const T& operator()(const unsigned& row, const unsigned& col) const;

    // Access the row and column sizes                                                                                                                                                                                              
    unsigned get_rows() const;
    unsigned get_cols() const;

};

#endif // MATRIXLIB_H_
