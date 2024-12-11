#include <iostream>
#include <gtest/gtest.h>

unsigned max(unsigned a, unsigned b, unsigned c, unsigned d ){
        if ((a>=b)&&(a>=c)&&(a>=d)) return a;
        else if ((b>=a)&&(b>=c)&&(b>=d)) return b;
        else if ((c>=b)&&(c>=a)&&(c>=d)) return c;
        else return d;
}

unsigned testic(unsigned*** p, int n){
    unsigned sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
                    for (int i = 0; i < n; i++)
                    {
                        sum1 += p[0 + i][0 + i][0 + i];
                        sum2 += p[0 + i][n-1 - i][n - 1 -i];
                        sum3 += p[n - 1 - i][0 + i][n - 1 - i];
                        sum4 += p[0 + i][0 + i][n - 1 - i];
                    }
                    unsigned res = max(sum1, sum2, sum3, sum4);
    return res;
    
}

TEST( TestCube, testicsame) {
    
    const int n = 3;
    
    // Создаем тестовую матрицу

     unsigned ***p = new unsigned**[n];
                    for (unsigned i = 0; i < n ; i++) {
                        p[i] = new unsigned*[n];
                        for ( unsigned j = 0; j < 3; j++) {
                            p[i][j] =  new unsigned[n];
                        }
                    }
    
    p[0][0][0] = 10; p[0][0][1] = 1; p[0][0][2] = 10;
    p[0][1][0] = 1; p[0][1][1] = 1; p[0][1][2] = 1;
    p[0][2][0] = 1; p[0][2][1] = 1; p[0][2][2] = 1;

    p[1][0][0] = 1; p[1][0][1] = 1; p[1][0][2] = 1;
    p[1][1][0] = 1; p[1][1][1] = 10; p[1][1][2] = 1;
    p[1][2][0] = 1; p[1][2][1] = 1; p[1][2][2] = 1;

    p[2][0][0] = 1; p[2][0][1] = 1; p[2][0][2] = 1;
    p[2][1][0] = 1; p[2][1][1] = 1; p[2][1][2] = 1;
    p[2][2][0] = 10; p[2][2][1] = 1; p[2][2][2] = 10;


    unsigned res = testic(p, n);

    
    EXPECT_EQ(res, 30);

    for(int j = 0; j < n; j++){
        for( int i = 0; i < n; i++){
                    delete[] p[j][i];
                    p[j][i] = nullptr;
                }
        delete[] p[j];
        p[j] = nullptr;
    }
                delete[] p;
                p = nullptr;
}

TEST( TestCube, testicsumF) {
    
    const int n = 3;
    
    // Создаем тестовую матрицу

     unsigned ***p = new unsigned**[n];
                    for (unsigned i = 0; i < n ; i++) {
                        p[i] = new unsigned*[n];
                        for ( unsigned j = 0; j < 3; j++) {
                            p[i][j] =  new unsigned[n];
                        }
                    }
    
    p[0][0][0] = 1; p[0][0][1] = 1; p[0][0][2] = 10;
    p[0][1][0] = 1; p[0][1][1] = 1; p[0][1][2] = 1;
    p[0][2][0] = 1; p[0][2][1] = 1; p[0][2][2] = 1;

    p[1][0][0] = 1; p[1][0][1] = 1; p[1][0][2] = 1;
    p[1][1][0] = 1; p[1][1][1] = 10; p[1][1][2] = 1;
    p[1][2][0] = 1; p[1][2][1] = 1; p[1][2][2] = 1;

    p[2][0][0] = 1; p[2][0][1] = 1; p[2][0][2] = 1;
    p[2][1][0] = 1; p[2][1][1] = 1; p[2][1][2] = 1;
    p[2][2][0] = 14; p[2][2][1] = 1; p[2][2][2] = 1;

    unsigned res = testic(p, n);

    
    EXPECT_EQ(res, 34);


    for(int j = 0; j < n; j++){
        for( int i = 0; i< n; i++){
                    delete[] p[j][i];
                    p[j][i] = nullptr;
                }
        delete[] p[j];
        p[j] = nullptr;
    }
                delete[] p;
                p = nullptr;
}

TEST( TestCube, testicsumThr) {
    
    const int n = 3;
    
    // Создаем тестовую матрицу

     unsigned ***p = new unsigned**[n];
                    for (unsigned i = 0; i < n ; i++) {
                        p[i] = new unsigned*[n];
                        for ( unsigned j = 0; j < 3; j++) {
                            p[i][j] =  new unsigned[n];
                        }
                    }
    
    p[0][0][0] = 1; p[0][0][1] = 1; p[0][0][2] = 1;
    p[0][1][0] = 1; p[0][1][1] = 1; p[0][1][2] = 1;
    p[0][2][0] = 13; p[0][2][1] = 1; p[0][2][2] = 1;

    p[1][0][0] = 1; p[1][0][1] = 1; p[1][0][2] = 1;
    p[1][1][0] = 1; p[1][1][1] = 10; p[1][1][2] = 1;
    p[1][2][0] = 1; p[1][2][1] = 1; p[1][2][2] = 1;

    p[2][0][0] = 1; p[2][0][1] = 1; p[2][0][2] = 10;
    p[2][1][0] = 1; p[2][1][1] = 1; p[2][1][2] = 1;
    p[2][2][0] = 1; p[2][2][1] = 1; p[2][2][2] = 1;


    unsigned res = testic(p, n);
    
    EXPECT_EQ(res, 33);


    for(int j = 0; j < n; j++){
        for( int i = 0; i<n; i++){
                    delete[] p[j][i];
                    p[j][i] = nullptr;
                }
        delete[] p[j];
        p[j] = nullptr;
    }
                delete[] p;
                p = nullptr;
}

TEST( TestCube, testicsumOne) {
    
    const int n = 3;
    
    // Создаем тестовую матрицу

     unsigned ***p = new unsigned**[n];
                    for (unsigned i = 0; i < n ; i++) {
                        p[i] = new unsigned*[n];
                        for ( unsigned j = 0; j < 3; j++) {
                            p[i][j] =  new unsigned[n];
                        }
                    }
    
    p[0][0][0] = 10; p[0][0][1] = 1; p[0][0][2] = 1;
    p[0][1][0] = 1; p[0][1][1] = 1; p[0][1][2] = 1;
    p[0][2][0] = 1; p[0][2][1] = 1; p[0][2][2] = 1;

    p[1][0][0] = 1; p[1][0][1] = 1; p[1][0][2] = 1;
    p[1][1][0] = 1; p[1][1][1] = 10; p[1][1][2] = 1;
    p[1][2][0] = 1; p[1][2][1] = 1; p[1][2][2] = 1;

    p[2][0][0] = 1; p[2][0][1] = 1; p[2][0][2] = 1;
    p[2][1][0] = 1; p[2][1][1] = 1; p[2][1][2] = 1;
    p[2][2][0] = 1; p[2][2][1] = 1; p[2][2][2] = 10;


    unsigned res = testic(p, n);

    
    EXPECT_EQ(res, 30);


    for(int j = 0; j < n; j++){
        for( int i = 0; i<n; i++){
                    delete[] p[j][i];
                    p[j][i] = nullptr;
                }
        delete[] p[j];
        p[j] = nullptr;
    }
                delete[] p;
                p = nullptr;
}

TEST( TestCube, testicsumTwo) {
    
    const int n = 3;
    
    // Создаем тестовую матрицу

     unsigned ***p = new unsigned**[n];
                    for (unsigned i = 0; i < n ; i++) {
                        p[i] = new unsigned*[n];
                        for ( unsigned j = 0; j < 3; j++) {
                            p[i][j] =  new unsigned[n];
                        }
                    }
    
    p[0][0][0] = 1; p[0][0][1] = 1; p[0][0][2] = 1;
    p[0][1][0] = 1; p[0][1][1] = 1; p[0][1][2] = 1;
    p[0][2][0] = 1; p[0][2][1] = 1; p[0][2][2] = 11;

    p[1][0][0] = 1; p[1][0][1] = 1; p[1][0][2] = 1;
    p[1][1][0] = 1; p[1][1][1] = 10; p[1][1][2] = 1;
    p[1][2][0] = 1; p[1][2][1] = 1; p[1][2][2] = 1;

    p[2][0][0] = 10; p[2][0][1] = 1; p[2][0][2] = 1;
    p[2][1][0] = 1; p[2][1][1] = 1; p[2][1][2] = 1;
    p[2][2][0] = 1; p[2][2][1] = 1; p[2][2][2] = 10;


    unsigned res = testic(p, n);

    
    EXPECT_EQ(res, 31);


    for(int j = 0; j < n; j++){
        for( int i = 0; i<n; i++){
                    delete[] p[j][i];
                    p[j][i] = nullptr;
                }
        delete[] p[j];
        p[j] = nullptr;
    }
                delete[] p;
                p = nullptr;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}