/**

simple 2x2 tranpose example

*/
#include<iostream>
#include<cstdlib>

#include "matrixlib.h"


int main(int argc, char** argv) {

MyMatrix<int> A(2,2,0);

for(int i=0;i<2;i++){
for (int j=0; j<2;j++){
A(i,j) = rand()%10+1;
std::cout << A(i,j) << " ";

}
std::cout<< "\n";
}

MyMatrix<int> B = ~A;


std::cout << B;


return 0;
}
