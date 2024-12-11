#include <iostream>

#include <gtest/gtest.h>

// Функция для подсчета отрицательных элементов ниже побочной диагонали
int countNegativeBelowSecondaryDiagonal(double** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i + j > rows - 1) && (matrix[i][j] < 0)) {
                count++;
            }
        }
    }
    return count;
}


TEST(countNegative, TestNegativeCount) {
    const int rows = 3;
    const int cols = 3;
    
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }

    
    matrix[0][0] = 1;   matrix[0][1] = 2;   matrix[0][2] = 3;
    matrix[1][0] = -1;  matrix[1][1] = -2;  matrix[1][2] = 4;
    matrix[2][0] = -3;  matrix[2][1] = 5;   matrix[2][2] = -6;

    EXPECT_EQ(countNegativeBelowSecondaryDiagonal(matrix, rows, cols), 1); // только matrix[2][2] отрицательный

    
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(countNegative, TestNegativeCountt) {
    const int rows = 3;
    const int cols = 3;
    
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }

    
    matrix[0][0] = 1;   matrix[0][1] = 2;   matrix[0][2] = 3;
    matrix[1][0] = -1;  matrix[1][1] = -2;  matrix[1][2] = 4;
    matrix[2][0] = -3;  matrix[2][1] = 5;   matrix[2][2] = 1;

    EXPECT_EQ(countNegativeBelowSecondaryDiagonal(matrix, rows, cols), 0);
    
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(countNegative, TestNegativeCounttt) {
    const int rows = 3;
    const int cols = 3;
    
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }

    
    matrix[0][0] = 1;   matrix[0][1] = 2;   matrix[0][2] = -3;
    matrix[1][0] = -1;  matrix[1][1] = -2;  matrix[1][2] = -4;
    matrix[2][0] = -3;  matrix[2][1] = -5;   matrix[2][2] = -6;

    EXPECT_EQ(countNegativeBelowSecondaryDiagonal(matrix, rows, cols), 3); 

    
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}