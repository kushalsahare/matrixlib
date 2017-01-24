
#include <gtest/gtest.h>
#include <matrixlib.h>

TEST(MyMatrix, Constructor) {
  MyMatrix A(5, 5, 1.0);
}

TEST(MyMatrix, MatrixMultiplication) {
  MyMatrix A(2, 2, 0.0);
  std::vector<Amplitude> rho1(4, 1);
  std::vector<Amplitude> rho2(4, 0);
  a.apply(2, &rho1[0], &rho2[0]);
  Amplitude expected[] = {0, Amplitude(0, -1), Amplitude(0, 1), 0};
  EXPECT_RANGES_EQ(expected, expected + 4, rho2.begin(), rho2.end());
}

TEST(MyMatrix, ApplySmSp) {
  MyMatrix a(1, 1, 1.0);
  std::vector<Amplitude> rho1(4, 1);
  std::vector<Amplitude> rho2(4, 0);
  a.apply(2, &rho1[0], &rho2[0]);
  Amplitude expected[] = {0, Amplitude(0, 1), Amplitude(0, -1), 0};
  EXPECT_RANGES_EQ(expected, expected + 4, rho2.begin(), rho2.end());
}

TEST(MyMatrix, ApplySm) {
  MyMatrix a(0, 1, 1.0);
  std::vector<Amplitude> rho1(4, 1);
  std::vector<Amplitude> rho2(4, 0);
  a.apply(2, &rho1[0], &rho2[0]);
  Amplitude expected[] = {0, 0, 0, 0};
  EXPECT_RANGES_EQ(expected, expected + 4, rho2.begin(), rho2.end());
}

TEST(MyMatrix, ApplySp) {
  MyMatrix a(1, 0, 1.0);
  std::vector<Amplitude> rho1(4, 1);
  std::vector<Amplitude> rho2(4, 0);
  a.apply(2, &rho1[0], &rho2[0]);
  Amplitude expected[] = {0, 0, 0, 0};
  EXPECT_RANGES_EQ(expected, expected + 4, rho2.begin(), rho2.end());
}

TEST(MyMatrix, TraceSp) {
  MyMatrix a(1, 0, 1.0);
  CheckLindbladTraceProperty(a, 2);
}

TEST(MyMatrix, HermiticitySp) {
  MyMatrix a(1, 0, 1.0);
  CheckLindbladHermiticityProperty(a, 2);
}

TEST(MyMatrix, TraceSpSm) {
  MyMatrix a(1, 1, 1.0);
  CheckLindbladTraceProperty(a, 2);
}

TEST(MyMatrix, HermiticitySpSm) {
  MyMatrix a(1, 1, 1.0);
  CheckLindbladHermiticityProperty(a, 2);
}

TEST(MyMatrix, HermiticityComplexMatElem) {
  MyMatrix a(0, 1, Amplitude(2.3, 4.8));
  CheckLindbladHermiticityProperty(a, 2);
}

TEST(MyMatrix, Diagonal) {
  MyMatrix a(1, 0, 0.0);
  EXPECT_FALSE(a.isDiagonal());
  MyMatrix b(0, 0, 0.0);
  EXPECT_TRUE(b.isDiagonal());
}

TEST(MyMatrix, DiagonalEntryHasSameRowAsCol) {
  MyMatrix a(0, 0, 1.0);
  ASSERT_TRUE(a.isDiagonal());
  EXPECT_EQ(a.getRow(), a.getCol());
}
