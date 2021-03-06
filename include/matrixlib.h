/**
 Matrix Library for Brain Corps
 Purpose: Matrix library for matrix multiplication and transpose 
  
 @author Kushal Sahare
*/

/*!\brief Matrix library for computation
* This is a matrix library for creating matrices
and carrying our matrix operations like matrix multiplication
and matrix transpose

*/
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
  unsigned rows_; /*!< number of rows*/
  unsigned cols_; /*!< number of columns*/


 public:

  /*constructor
    Creates a Matrix of dimension specified by the parameter
    rows, cols and intial value
    @param rows  no of rows
    @param cols  no of colums
    @param intial intial value
  
  */
  MyMatrix(unsigned rows, unsigned cols, const T& initial);
  /*
  Copy constructor
  */
  MyMatrix(const MyMatrix<T>& rhs);
  /*
  Assignment operator
  */
  MyMatrix<T>& operator=(const MyMatrix<T>& rhs);

  /**
   Matrix Multiplication
  */                                                                                                                                                                                               
  MyMatrix<T> operator*(const MyMatrix<T>& rhs) const;

/** operator overloading to display matrix

*/

template <class U>
friend std::ostream& operator<<(std::ostream& os, const MyMatrix<U>& obj) ;


  /**
   Matrix Transpose
  */
  MyMatrix<T> transpose() const ;
  MyMatrix<T> operator~() const ;

  /**
 Returns the element at location (i,j)th position
 *@param row i of (i,j)th element
 *@param col j of (i,j)th element
*/                                                                                                                                                                                               
  T& operator()(const unsigned& row, const unsigned& col);
  const T& operator()(const unsigned& row, const unsigned& col) const ;

/** 
Returns number of rows
@return unsigned int

*/                                                                                                                                                                                         
  unsigned get_rows() const;

/** 
Returns number of columns
@return unsigned int

*/ 
  unsigned get_cols() const;

 virtual ~MyMatrix();


};
#include "../src/matrixlib.cpp"
#endif // MATRIXLIB_H_
