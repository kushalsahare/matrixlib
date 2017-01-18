#include "matrixlib.h"

template<class T>
MyMatrix<T>::MyMatrix(unsigned rows, unsigned cols, const T& initial):rows_(rows),cols_(cols) {

  if( rows_ == 0 || cols_ == 0 )
    throw std::range_error("Degenerate Matrix creation!Aborted");

  mat(rows_, std::vector<T>(cols_,initial)); 
      //    mat.resize(rows_);
      //    for (unsigned i=0; i<mat.size(); i++) {
      //        mat[i].resize(cols, initial);
      //    }

      }

      //copy constructor


template<class T>
MyMatrix<T>::MyMatrix(const MyMatrix<T>& rhs):rows_(rhs.rows_),cols_(rhs.cols_), mat_(rhs.mat_){}

//destructor
template<class T>
MyMatrix<T>::~MyMatrix() {}

template<class T>
MyMatrix<T>& MyMatrix<T>::operator=( const MyMatrix<T>& rhs )
{
  if(rhs.rows_ != rows_ && rhs.cols_ != cols_ )
    throw std::domain_error("matrix op= not of same order");
  if (&rhs == this){
    return *this;
  }
  for(unsigned i=0;i<rows_*cols_;i++)
    this->elements_[i] = rhs.elements_[i];
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
        temp.mat[i][j] += this->mat_[i][k] * rhs(k,j);
      }
    }
  }

  return temp;
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
void MyMatrix<T>::range_check( unsigned i, unsigned j ) const
{
  if( i<0 ||  rows_ <= i )
    throw std::range_error("matrix access row out of range");
  if( j < 0 || cols_ <= j  )
    throw std::range_error("matrix access col out of range");
}

template<class T>
T& MyMatrix<T>::operator()( const unsigned& i, const unsigned& j ) {
#ifdef RANGE_CHECK
  range_check(i,j);
#endif
  return mat_[i][j];
}

template<class T>
const T& MyMatrix<T>::operator()( const unsigned& i, const unsigned& j ) const{
#ifdef RANGE_CHECK
  range_check(i,j);
#endif
  return mat_[i][j];
}

// Get the number of rows of the matrix                                                                                                                                       
template<class T>
unsigned MyMatrix<T>::get_rows() const {
  return this->rows;
}

// Get the number of columns of the matrix                                                                                                                                    
template<class T>
unsigned MyMatrix<T>::get_cols() const {
  return this->cols;
}

