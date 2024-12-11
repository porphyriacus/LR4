#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int IncorrectInput(){

    int n;
    char control;
    while( scanf("%d%c", & n, & control) != 2 || control != '\n' ){
            printf("Неверный формат ввода.\n");
            while (getchar() != '\n') {};
            
    }
    if ( n > 0 ) return n;
    printf("Неверный формат ввода. ");
    return 0;
    }

int main()
{
    printf("Программа строит магический квадрат. Порядок квадрата задаётся пользователем. Максимальный размер магического квадрата не превышает )))");
    printf("Программа выполнена Саранцевой Дарьей, учащейся группы 453502\n");
    for (int i = 0; i < 10; i++) {
       printf("*********");
    }
    
    while (1)
    {
        printf("\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу.");
        int status = IncorrectInput();
        if (status == 2) return 0;
        if( status == 1) {
               
                while (1){
                    printf("Введите n, которое задаст размер магического квадрата.");
                    int n = IncorrectInput(); //n = row = col = izm;
                    if (n <= 0) {
                        //printf("Неверный формат ввода.");
                        continue;
                    }

                        if ( n % 2 != 0){
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
                            
                            printf("Массив :\n");
                            for ( unsigned j = (n - 1)/2; j < n + (n - 1)/2 ; j++){
                                for (unsigned k = (n - 1)/2; k < n + (n - 1)/2; k++){
                                    printf("%5d ", p[j][k]);
                                }
                            printf("\n");  
                            }
                    
                            for (int k = 0; k < n + n - 1; k++) {   
                                free(p[k]);  
                            }
                            free(p);
                            p = NULL;
                            
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
                        printf("Массив :\n");
                        for (int i = 0; i < n; i++){
                            for (int j = 0; j < n; j++){
                                printf("%5d ", p[i][j]);
                            }
                         printf("\n");
                        }
                        for (int i = 0; i < n; i++){
                            free(p[i]);
                        }
                            
                        free(p);
                        p = NULL;
                        
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

                          printf("Массив :\n");
                        for (int i = 0; i < n; i++){
                            for (int j = 0; j < n; j++){
                                printf("%5d ", p[i][j]);
                            }
                         printf("\n");
                        }
                        for (int i = 0; i < n; i++){
                            free(p[i]);
                        }
                            
                        free(p);
                        p = NULL;
                    }


                    break;
                }
                continue;
        }
        printf("Неверный формат ввода.");
    } 

}

