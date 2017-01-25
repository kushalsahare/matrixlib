#ifndef MATRIXLIB_CPP_
#define MATRIXLIB_CPP_


#include "matrixlib.h"


template<class T>
MyMatrix<T>::MyMatrix(unsigned int rows, unsigned int cols, const T& initial):rows_(rows),cols_(cols) {

  if( rows_ == 0 || cols_ == 0 )
    throw std::range_error("Degenerate Matrix creation!Aborted");

mat_.resize(rows_);
  for (unsigned i=0; i<mat_.size(); i++) {
    mat_[i].resize(cols_, initial);
  }

}


template<class T>
MyMatrix<T>::MyMatrix(const MyMatrix<T>& rhs):rows_(rhs.rows_),cols_(rhs.cols_), mat_(rhs.mat_){}


template<class T>
MyMatrix<T>& MyMatrix<T>::operator=( const MyMatrix<T>& rhs ) {
  if (&rhs != this){
     if(rhs.rows_ != rows_ && rhs.cols_ != cols_ )
     throw std::domain_error("matrix op= not of same order");
  for(unsigned i=0;i<rows_*cols_;i++)
    this->elements_[i] = rhs.elements_[i];
}
  return *this;
}


template<class T>
MyMatrix<T> MyMatrix<T>::operator*( const MyMatrix<T>& rhs ) const{
  if(cols_ != rhs.rows_ )
    throw std::domain_error("Aborted! Matrix multiplication dimension mismatch! number of columns of the first matrix should be equal to number of rows of the second matrix");
  
  MyMatrix<T> temp(rows_, cols_, T(0.0));

  for (unsigned i=0; i<rows_; i++) {
    for (unsigned j=0; j<rhs.cols_; j++) {
      for (unsigned k=0; k<cols_; k++) {
        temp.mat_[i][j] += this->mat_[i][k] * rhs(k,j);
      }
    }
  }

  return temp;
}


template<class U>
std::ostream& operator<<(std::ostream& os, const MyMatrix<U>& obj) {

unsigned int rows= obj.get_rows();
unsigned int cols= obj.get_cols();
for(int i=0; i < rows; i++){
 for (int j=0; j < cols; j++){
      os << obj(i,j) << " ";
}
os << "\n";
}

return os;
}


// Calculate a transpose of this matrix                                                                                                                                       
template<class T>
MyMatrix<T> MyMatrix<T>::transpose()const{
  MyMatrix<T> temp(rows_, cols_, T(0.0));

  for (unsigned i=0; i<rows_; i++) {
    for (unsigned j=0; j<cols_; j++) {
      temp(i,j) = this->mat_[j][i];
    }
  }

  return temp;
}


template<class T>
MyMatrix<T> MyMatrix<T>::operator~()const{
  return this->transpose();
}

template<class T>
T& MyMatrix<T>::operator()( const unsigned& i, const unsigned& j ) {
if( i<0 ||  rows_ <= i )
    throw std::range_error("matrix access row out of range");
if( j < 0 || cols_ <= j  )
    throw std::range_error("matrix access col out of range");

  return this->mat_[i][j];
}

template<class T>
const T& MyMatrix<T>::operator()( const unsigned& i, const unsigned& j ) const {
if( i<0 ||  rows_ <= i )
    throw std::range_error("matrix access row out of range");
if( j < 0 || cols_ <= j  )
    throw std::range_error("matrix access col out of range");

  return this->mat_[i][j];
}



// Get the number of rows of the matrix                                                                                                                                       
template<class T>
unsigned MyMatrix<T>::get_rows() const {
  return this->rows_;
}

// Get the number of columns of the matrix                                                                                                                                    
template<class T>
unsigned MyMatrix<T>::get_cols() const {
  return this->cols_;
}


//destructor
template<class T>
MyMatrix<T>::~MyMatrix() {}

#endif //MATRIXLIB_CPP_
