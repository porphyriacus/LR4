#include <gtest/gtest.h>
void processField(char** fld, int n, int m) {
    int i, j, N = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++, N = 0) {
            if (fld[i][j] == '.') {
                if (fld[i - 1][j - 1] == '*') N++;
                if (fld[i - 1][j] == '*') N++;
                if (fld[i - 1][j + 1] == '*') N++;
                if (fld[i][j - 1] == '*') N++;
                if (fld[i][j + 1] == '*') N++;
                if (fld[i + 1][j - 1] == '*') N++;
                if (fld[i + 1][j] == '*') N++;
                if (fld[i + 1][j + 1] == '*') N++;
                if (N!=0) {
                    fld[i][j] = (char)(48 + N);
                }
            }
        }
    }
}
TEST(SaperTest, TestFieldProcessing) {
    int n = 5, m = 5;
    char** fld = new char*[n+2];
        fld[0] = new char[m+2]{'.', '.', '.', '.', '.', '.', '.'};
        fld[1] = new char[m+2]{'.', '.', '.', '.', '.', '.', '.'};
        fld[2] = new char[m+2]{'.', '.', '*', '*', '*', '.', '.'};
        fld[3] = new char[m+2]{'.', '.', '*', '.', '*', '.', '.'};
        fld[4] = new char[m+2]{'.', '.', '*', '*', '*', '.', '.'};
        fld[5] = new char[m+2]{'.', '.', '.', '.', '.', '.', '.'};
        fld[6] = new char[m+2]{'.', '.', '.', '.', '.', '.', '.'};
    
    char** expected = new char*[n];
    expected[0] = new char[m]{'1', '2', '3', '2', '1'};
    expected[1] = new char[m]{'2', '*', '*', '*', '2'};
    expected[2] = new char[m]{'3', '*', '8', '*', '3'};
    expected[3] = new char[m]{'2', '*', '*', '*', '2'};
    expected[4] = new char[m]{'1', '2', '3', '2', '1'};

    processField(fld, n, m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            EXPECT_EQ(fld[i][j], expected[i-1][j-1]);
        }
    }
    for (int i = 0; i < n + 2; i++) {
            delete[] fld[i];
    }
    delete[] fld;
    for (int i = 0; i < n; i++) {
        delete[] expected[i];
    }
    delete[] expected;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//g++ -o test test.cpp -lgtest -lpthread