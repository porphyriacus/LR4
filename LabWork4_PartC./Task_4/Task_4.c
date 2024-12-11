
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


unsigned max(unsigned a, unsigned b, unsigned c, unsigned d ){
    if ((a>=b)&&(a>=c)&&(a>=d)) return a;
    else if ((b>=a)&&(b>=c)&&(b>=d)) return b;
    else if ((c>=b)&&(c>=a)&&(c>=d)) return c;
    else return d;
}

int main()
{
    printf("Дан трёхмерный динамический массив размером n^3 целых неотрицательных чисел. Программа определяет диагональ с наибольшей суммой чисел и выводит её значение.");
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
                while(1){
                    printf("Введите натуральное число n, задающее размерность трехмерного массива размером n^3");
                    unsigned n = IncorrectInput(); //n = row = col = izm;
                    if (n <= 0) {
                        continue;
                    }
               
                    unsigned ***p = (unsigned ***)malloc( n * sizeof(unsigned **));
                    for (unsigned i = 0; i < n; i++) {
                        p[i] = (unsigned **)malloc(n * sizeof(unsigned *));
                        for ( unsigned j = 0; j < n; j++) {
                            p[i][j] = (unsigned *)malloc(n * sizeof(unsigned));
                        }
                    }
                    srand(time(NULL));
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            for (int k = 0; k < n; k++) {
                                p[i][j][k] = 1 + rand() % 100;
                            }
                        }
                    }
    
                    printf("Массив :\n");
                    for (unsigned i = 0; i < n; i++){
                        printf("измерение %d:\n", i);
                        for ( unsigned j = 0; j < n; j++){
                            for (unsigned k = 0; k < n; k++){
                                printf("%u ", p[i][j][k]);
                            }
                        printf("\n");  
                        }
                        printf("\n");
                    }

                    unsigned sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
                    for (int i = 0; i < n; i++)
                    {
                        sum1 += p[0 + i][0 + i][0 + i];
                        sum2 += p[0 + i][n-1 - i][n - 1 -i];
                        sum3 += p[n - 1 - i][n - 1 - i][n - 1 - i];
                        sum4 += p[n - 1 - i][0 + i][0 + i];
                    }
                    unsigned res = max(sum1, sum2, sum3, sum4);
                    printf("Значение суммы чисел диагонали, с наибольшей суммой чисел : %u ", res);
                    


                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            free(p[i][j]);
                        }
                        free(p[i]);
                    }
                    free(p);
                    p = NULL;

                    break;
                }
        }

    }

    printf("Неверный формат ввода.");
}


