
#include <gtest/gtest.h>
#include <matrixlib.h>

TEST(GeneralDecayOperator, IsConstructibleFromMatrix) {
  GeneralDecayOperator op(SparseMatrix(SparseMatrixEntry(1, 2, 1.0)));
}

TEST(GeneralDecayOperator, IsNullOperatorWhenEmpty) {
  SparseMatrix m;
  GeneralDecayOperator op(m);
  std::vector<Amplitude> rho(4, 1);
  std::vector<Amplitude> result(4, 0);
  op.apply(2, &rho[0], &result[0]);
  for (int i = 0; i < 4; ++i) {
    EXPECT_DOUBLE_EQ(0.0, result[i].real()) << "(i == " << i << ")";
    EXPECT_DOUBLE_EQ(0.0, result[i].imag()) << "(i == " << i << ")";
  }
}

TEST(GeneralDecayOperator, ProducesCorrectDensityMatrixForEToGDecay) {
  double gamma = 0.2;
  GeneralDecayOperator op(
      SparseMatrix(SparseMatrixEntry(0, 1, std::sqrt(gamma))));
  std::vector<Amplitude> rho1(4, 1);
  std::vector<Amplitude> rho2(4, 0);
  op.apply(2, &rho1[0], &rho2[0]);
  EXPECT_DOUBLE_EQ(gamma, rho2[0].real());
  EXPECT_DOUBLE_EQ(0.0, rho2[0].imag());
  EXPECT_DOUBLE_EQ(-gamma, rho2[3].real());
  EXPECT_DOUBLE_EQ(0.0, rho2[3].imag());
  EXPECT_DOUBLE_EQ(-0.5 * gamma, rho2[1].real());
  EXPECT_DOUBLE_EQ(0.0, rho2[1].imag());
  EXPECT_DOUBLE_EQ(-0.5 * gamma, rho2[2].real());
  EXPECT_DOUBLE_EQ(0.0, rho2[2].imag());
}

TEST(GeneralDecayOperator, IsTracelessForEToG) {
  GeneralDecayOperator op(SparseMatrix(SparseMatrixEntry(0, 1, 0.2)));
  CheckLindbladTraceProperty(op, 2);
}

TEST(GeneralDecayOperator, IsTracelessInGeneralCase) {
  SparseMatrix lambda;
  lambda.add(SparseMatrixEntry(0, 3, 0.2));
  lambda.add(SparseMatrixEntry(1, 3, 0.3));
  lambda.add(SparseMatrixEntry(2, 3, 0.2));
  GeneralDecayOperator op(lambda);
  CheckLindbladTraceProperty(op, 4);
}

TEST(GeneralDecayOperator, IsHermitianInGeneralCase) {
  SparseMatrix lambda;
  lambda.add(SparseMatrixEntry(0, 3, 0.2));
  lambda.add(SparseMatrixEntry(1, 3, 0.3));
  lambda.add(SparseMatrixEntry(2, 3, 0.2));
  GeneralDecayOperator op(lambda);
  CheckLindbladHermiticityProperty(op, 4);
}
