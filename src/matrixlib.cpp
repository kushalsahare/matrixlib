#include "MyMatrixlib.h"

template<class T>
BC_LIB::MyMatrix<T>::MyMatrix(){


}

template<class T>
BC_LIB::MyMatrix<T>::MyMatrix(const unsigned int rows, const unsigned int cols): rows_(rows), cols_(col), elements_(rows*cols, T(0.0)){

    if (rows_==0 || cols_==0){
        throw std::range_error("Attempt to create a degenerate matrix");
    }   

    if(elements){
        for (unsigned int i=0; i< rows_*cols_ ; ++i){
            this->elements_[i] = elements[i];
        }

    }

}

template<class T>
BC_LIB::MyMatrix<T>::MyMatrix( const MyMatrix<T>& copy )
  : rows_(copy.rows_), cols(copy.cols_), elements_(copy.elements_){}

template<class T>
MyMatrix<T>& BC_LIB::MyMatrix<T>::operator=( const MyMatrix<T>& copy )
{
   if(copy.rows_ != rows_ && copy.cols_ != cols_ )
      throw std::domain_error("Copying failed!Matrices are not of same dimensions.");
   for(unsigned i=0;i<rows*cols;i++)
      this->elements_[i] = copy.elements_[i];
   return *this;
}
