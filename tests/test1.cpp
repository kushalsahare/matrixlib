
#include <gtest/gtest.h>
#include <matrixlib.h>
#include <cstdlib>

TEST(MyMatrix, Constructor) {
    MyMatrix<int> A(2, 2, 1);
}

TEST(MyMatrix, InitializeMatrix){

    MyMatrix<int> A(2,10,0);

    EXPECT_EQ(2, A.get_rows());
    EXPECT_EQ(10, A.get_cols());

    for(int i=0; i<A.get_rows(); i++){
    for(int j=0; j<A.get_cols(); j++){

    EXPECT_EQ(0, A(i,j));   

}

}
}
TEST(MyMatrix, transpose) {

    MyMatrix<int> A(2, 2, 1);

    for (int i=0; i< A.get_rows() ; i++){
        for (int j=0; j< A.get_cols(); j++){

            A(i,j) = rand()%10+1;
        }

    }

    MyMatrix<int> B = ~A;
    
    for (int i = 0; i < A.get_rows(); i++) {
        for(int j =0; j < A.get_rows(); j++)
            EXPECT_EQ(A(i,j), B(j,i)) << "Matrix A and B differ at index " << i << " " << j;
    }


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

