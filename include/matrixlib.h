#ifndef MATRIXLIB_H_
#define MATRIXLIB_H_

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdexcept>

#define RANGE_CHECK

template <class T>

class MyMatrix {

  std::vector<std::vector<T> > mat_;
  unsigned rows_;
  unsigned cols_;


 protected:
  void range_check(unsigned i, unsigned j) const;

 public:

  //constructor

  MyMatrix(unsigned rows, unsigned cols, const T& initial);
  MyMatrix(const MyMatrix<T>& rhs);
  virtual ~MyMatrix();

  // Operator overloading 
  MyMatrix<T>& operator=(const MyMatrix<T>& rhs);

  // Matrix Multiplication                                                                                                                                                                                               
  MyMatrix<T> operator*(const MyMatrix<T>& rhs) const;


  // Matrix Transpose
  MyMatrix<T> transpose() const ;
  MyMatrix<T> operator~() const ;

  // Access the individual elements                                                                                                                                                                                               
  T& operator()(const unsigned& row, const unsigned& col);
  const T& operator()(const unsigned& row, const unsigned& col) const ;

  // Access the row and column sizes                                                                                                                                                                                              
  unsigned get_rows() const;
  unsigned get_cols() const;

};

#endif // MATRIXLIB_H_
