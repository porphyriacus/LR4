#include <iostream>
#include <gtest/gtest.h>
#include <sstream>

void ProcessMatrix(std::istream &input, std::ostream &output, int N) {
    int matrix[10][10];
    int max = -100, min = 100, strmax = -1, strmin = -1;

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input >> matrix[i][j];
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                strmax = i;
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                strmin = i;
            }
        }
    }

    // перестановк строк
    if (strmax == strmin) {
        output << "Минимальный и максимальный элементы находятся в одной строке (" << strmin << ")\n";
    } else {
        for (int j = 0; j < N; j++) {
            std::swap(matrix[strmax][j], matrix[strmin][j]);
        }
         
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            output << matrix[i][j] << " ";
        }
        output << '\n';
    }
    }

   
}

TEST(MatrixTest, SameRow) {
    std::stringstream input("1 2 3 4\n");
    std::stringstream output;

    ProcessMatrix(input, output, 1);

    EXPECT_EQ(output.str(), "Минимальный и максимальный элементы находятся в одной строке (0)\n");
}

TEST(MatrixTest, DifferentRows) {
    std::stringstream input("1 2 3\n4 5 6\n");
    std::stringstream output;

    ProcessMatrix(input, output, 2);
    EXPECT_EQ(output.str().find("4 5 6\n1 2 3\n"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}