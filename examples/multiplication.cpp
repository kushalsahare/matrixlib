
#include<iostream>
#include<cstdlib>

#include "matrixlib.h"


int main(int argc, char** argv) {

// create matrix A
MyMatrix<int> A(2,2,0);


//display matrix A
for(int i=0;i<2;i++){
for (int j=0; j<2;j++){
A(i,j) = rand()%10+1;
std::cout << A(i,j) << " ";

}
std::cout<< "\n";
}

//create matrix B

MyMatrix<int> B(2,2,0);

for(int i=0;i<2;i++){
for (int j=0; j<2;j++){
B(i,j) = rand()%10+1;
std::cout << B(i,j) << " ";

}
std::cout<< "\n";
}

MyMatrix<int> C = A*B;
std::cout << C ;

return 0;
}
