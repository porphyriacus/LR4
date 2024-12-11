#include <iostream>
#include <gtest/gtest.h>
int MagicSq(int n){

                        int sum = 0;
                  
                        if(n == 2) return sum;

                        else if ( n % 2 != 0){
                            //нечетного порядка
                    
                            int **p = (int **)malloc((n + n - 1) * sizeof(int *));
                            for ( int j = 0; j < n + n - 1; j++) {
                                p[j] = (int *)malloc((n + n - 1) * sizeof(int));
                            }
                    
                            for ( int i = 0; i < n + n - 1; i++){
                                for ( int j = 0; j < n + n - 1; j++){
                                    p[i][j]=0;
                                }
                            }
                    
                            int ost = 0;
                            for ( int j = 0; j < n; j++){
                                p[j + 0][n - 1 - j] = 1 + ost;
                                int sum = p[j + 0][n - 1 - j];
                                for( int i = 0; i < n - 1; i++){
                                    p[j + 1 + i][n  - j + i] = sum + 1 + i;
                                }
                                ost = p[j + n - 1][n + n -2 - j];
                            }
                            
                            
                            for( int i = 0; i < n - 2; i++){
                                for( int k = 0; k <= i * 2; k += 2){
                                    p[i+n][n - 1 - i + k] = p[i][n - 1 - i +k];
                                    p[n - 1 - i + k][i+n] = p[n - 1 - i +k][i];

                                    p[n + n - 2 - i - n][n - 1 - i + k] = p[n + n - 2 - i ][n - 1 - i + k];
                                    p[n - 1 - i + k][n + n - 2 - i - n] = p[n - 1 - i + k][n + n - 2 - i ];
                                }
                            }
                            
                           
                                for (unsigned k = (n - 1)/2; k < n + (n - 1)/2; k++){
                                    sum += p[(n - 1)/2][k];
                                }
                            
                            

                            for (int k = 0; k < n + n - 1; k++) {   
                                free(p[k]);  
                            }
                            free(p);
                            p = NULL;
                            return sum;
                           
                            
                        }
                        else if ( n % 4 == 0){ //четного порядка 4, 8...
                        int** p = ( int**)malloc(n * sizeof(int*));
                        for (int i = 0; i < n; i++) {
                            p[i] = (int*)malloc(n * sizeof( int));
                        }
                        int k = n / 4, nomer = 0;
                        for (int i = 0; i < n; i++){
                            for (int j = 0; j < n; j++){
                                p[i][j] = i * n + j + 1;
                            }
                        }
                       for (int i = 0; i < k; i++){
                            for (int j = 0; j < k; j++){
                                for (int g = 0; g < 4; g++){
                                    p[4 * i + g][(j * 4) + g] = 0;
                                    p[(i + 1) * 4 - g - 1][(j * 4) + g] = 0;
                                }
                            }
                        }
                            
                        for (int i = n - 1; i >= 0; i--){
                            for (int j = n - 1; j >= 0; j--){
                                nomer++;
                                if (p[i][j] == 0){
                                    p[i][j] = nomer;
                                }   
                            }
                        }
                        
                        for (int j = 0; j < n; j++){
                                sum += p[0][j];
                            }
                        
                        for (int i = 0; i < n; i++){
                            free(p[i]);
                        }
                            
                        free(p);
                        p = NULL;
                        return sum;
                        
                        
                    }

                     else if ((n - 2) % 4 == 0){ //четного 6, 10..
                        int** p = (int**)malloc(n * sizeof( int*));
                        for (int i = 0; i < n; i++) {
                            p[i] = ( int*)malloc(n * sizeof( int));
                        }
                        int k = ((n - 2) / 4), nomer = 0;
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++){
                                p[i][j] = -2;
                            }
                        }
                        for (int i = 0; i < n; i++) {
                            p[i][i] = -1;
                            p[i][n - 1 - i] = -1;
                        }

                        for (int i = 0; i < 2 * k; i++) {
                            for (int j = i; j < 2 * k; j++){
                                p[i][j + 1] = -3;
                                p[i][n - j - 2] = -3;
                                p[n - 1 - i][j + 1] = -3;
                                p[n - 1 - i][n - j - 2] = -3;
                            }
                        }

                        for (int i = 0; i < k + 1; i++) {
                            for (int j = i; j < 2 * k + 1 - i; j++) {
                                p[k + j][i] = -4;
                                p[k + j][n - 1 - i] = -4;
                                p[i][k + j] = -4;
                                p[n - 1 - i][k + j] = -4;
                            }
                        }

                        for (int i = 0; i < k; i++){
                            for (int j = i; j < k; j++) {
                                p[k + 1 + j][i] = -3;
                                p[n - k - 2 - j][i] = -3;
                                p[i][k + 1 + j] = -2;
                                p[i][n - k - 2 - j] = -2;
                            }
                        }

                        for (int i = 0; i < k - 1; i++){
                            for (int j = i; j < k - 1; j++) {
                                p[k + 2 + j][n - 1 - i] = -3;
                                p[n - k - 3 - j][n - 1 - i] = -3;
                                p[n - 1 - i][k + 2 + j] = -2;
                                p[n - 1 - i][n - k - 3 - j] = -2;
                            }
                        }

                        for (int i = 0; i < n; i++){
                            for (int j = 0; j < n; j++){
                                nomer++;
                                if (p[j][i] == -1){
                                    p[j][i] = nomer;
                                }
                                
                                if (p[n - 1 - j][i] == -2){
                                    p[n - 1 - j][i] = nomer;
                                }

                                if (p[j][n - 1 - i] == -3){
                                    p[j][n - 1 - i] = nomer;
                                }

                                if (p[n - 1 - j][n - 1 - i] == -4){
                                    p[n - 1 - j][n - 1 - i] = nomer;
                                }
                            }
                        }
 
                       
                            for (int j = 0; j < n; j++){
                                sum += p[0][j];
                            }
                        
                        
                       
                        for (int i = 0; i < n; i++){
                            free(p[i]);
                        }
                            
                        free(p);
                        p = NULL;
                        return sum;
                        
                    } 
     return 0;
}

bool testic( int n){
    if(n == 2) return false;
    int sum = n * (n * n + 1) / 2;
    if(sum == MagicSq(n)) return true;
    else return false;
}

TEST( MagicSqu, mtgicOne) {
    int n = 1;
    bool res = testic(n);   
    EXPECT_EQ(res, true);
}

TEST( MagicSqu, mtgicTwo) {
    int n = 2;
    bool res = testic(n);   
    EXPECT_EQ(res, false);
}
TEST( MagicSqu, mtgicThr) {
    int n = 3;
    bool res = testic(n);   
    EXPECT_EQ(res, true);
}
TEST( MagicSqu, mtgicFour) {
    int n = 4;
    bool res = testic(n);   
    EXPECT_EQ(res, true);
}
TEST( MagicSqu, mtgicSix) {
    int n = 6;
    bool res = testic(n);   
    EXPECT_EQ(res, true);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}