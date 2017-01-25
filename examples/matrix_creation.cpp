
#include<iostream>
#include<cstdlib>

#include "matrixlib.h"


int main(int argc, char** argv) {

MyMatrix<int> A(5,5,0);

for(int i=0;i<5;i++){
for (int j=0; j<5;j++){
A(i,j) = rand()%10+1;
std::cout << A(i,j) << " ";

}
std::cout<< "\n";
}

MyMatrix<int> B = ~A;

std::cout << B ;


return 0;
}
