#include <gtest/gtest.h> 
#include "matrix.h" 

TEST(MatrixTest, CreateAndFree) { 
	Matrix m = create_matrix(2, 2); 
	EXPECT_EQ(m.rows, 2); 
	EXPECT_EQ(m.cols, 2); 
	EXPECT_NE(m.data, nullptr); 
	free_matrix(m); 
	} 

TEST(MatrixTest, InvalidSize) { 
	EXPECT_THROW(create_matrix(-1, 2), std::invalid_argument); 
} 

TEST(MatrixTest, MatrixAddition) { 
	Matrix A = create_matrix(2, 2); 
	Matrix B = create_matrix(2, 2); 

	A.data[0][0] = 1; A.data[0][1] = 2; 
	A.data[1][0] = 3; A.data[1][1] = 4; 

	B.data[0][0] = 5; B.data[0][1] = 6; 
	B.data[1][0] = 7; B.data[1][1] = 8; 

	Matrix C = matrix_add(A, B); 
	EXPECT_EQ(C.data[0][0], 6); 
	EXPECT_EQ(C.data[0][1], 8); 
	EXPECT_EQ(C.data[1][0], 10); 
	EXPECT_EQ(C.data[1][1], 12); 

	free_matrix(A); 
	free_matrix(B); 
	free_matrix(C); 
} 

TEST(MatrixTest, MatrixMultiplication) { 
	Matrix A = create_matrix(2, 2); 
	Matrix B = create_matrix(2, 2); 

	A.data[0][0] = 1; A.data[0][1] = 2; 
	A.data[1][0] = 3; A.data[1][1] = 4; 

	B.data[0][0] = 5; B.data[0][1] = 6; 
	B.data[1][0] = 7; B.data[1][1] = 8; 

	Matrix C = matrix_multiply(A, B); 
	EXPECT_EQ(C.data[0][0], 19); 
	EXPECT_EQ(C.data[0][1], 22); 
	EXPECT_EQ(C.data[1][0], 43); 
	EXPECT_EQ(C.data[1][1], 50); 

	free_matrix(A); 
	free_matrix(B); 
	free_matrix(C); 
}
TEST(MatrixTest, MatrixSum) { 
	// Создаем матрицу 2x2: [1, 2] 
	//                     [3, 4] 
	Matrix A = create_matrix(2, 2); 
	A.data[0][0] = 1; A.data[0][1] = 2; 
	A.data[1][0] = 3; A.data[1][1] = 4; 
	
	// Проверяем сумму: 1 + 2 + 3 + 4 = 10 
	EXPECT_DOUBLE_EQ(matrix_sum(A), 10.0); 
	free_matrix(A); 
} 

TEST(MatrixTest, MatrixSumEmpty) { 
	// Тест для "пустой" матрицы - используем небольшую матрицу с нулями 
	Matrix A = create_matrix(1, 1); 
	A.data[0][0] = 0.0;  // Единственный элемент = 0 
	EXPECT_DOUBLE_EQ(matrix_sum(A), 0.0); 
	free_matrix(A); 
} 
TEST(MatrixTest, MatrixSumInvalidMatrix) { 
	// Тест на обработку неинициализированной матрицы 
	Matrix A; 
	A.data = nullptr; 
	A.rows = 0; 
	A.cols = 0; 
	EXPECT_DOUBLE_EQ(matrix_sum(A), 0.0); 
	// Не нужно free_matrix - память не выделялась 
} 

TEST(MatrixTest, MatrixSumSingleElement) { 
	// Тест для матрицы 1x1 
	Matrix A = create_matrix(1, 1); 
	A.data[0][0] = 5.5; 
	EXPECT_DOUBLE_EQ(matrix_sum(A), 5.5); 
	free_matrix(A); 
} 