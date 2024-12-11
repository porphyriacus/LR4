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
    printf("На вход подаётся поле для игры в сапёр размером n*m символов(размер задается пользователем), где символ '.' означает пустое место, а символ  '*' - бомбу. Программа дополняет это поле числами, как в оригинальной игре.");
    printf("\nПрограмма выполнена Саранцевой Дарьей, учащейся группы 453502\n");
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
                    printf("Введите n, которое задаст ширину поля для игры в сапер.");
                    int n = IncorrectInput(); //n = row = col = izm;
                    if (n <= 0) {
                        continue;
                    }
                        while (1){
                             printf("Введите m, которое задаст ширину поля для игры в сапер.");
                             int m = IncorrectInput(); //n = row = col = izm;
                             if (m <= 0) {
                                continue;
                             }
                        
                            char **p = (char **)malloc((n + 2) * sizeof(char *));
                            for ( int j = 0; j < n + 2; j++) {
                                p[j] = (char *)malloc((m + 2) * sizeof(char));
                            }
                        
                            for (int i = 0; i < m + 2 ; i++){
                                p[0][i] = (0);
                                p[n+1][i]= (0);
                            }
                            
                            for (int i = 0; i < n + 2; i++){
                                
                                p[i][0] = (0);
                                p[i][m+1] = (0);
                            }

                            srand(time(NULL));

                            for (int i = 1; i < n + 1; i++) {
                                for (int j = 1; j < m + 1; j++) {
                                    if ( rand()%5 == 4) {
                                        p[i][j] = '*';     // бум
                                    }
                                    else{
                                        p[i][j] = '!';  
                                    }  
                                }
                            }
                               
                            for (int i = 1; i < n + 1; i++) {
                                for (int j = 1, sum = 0; j < m + 1; j++, sum = 0) {
                                    if (  p[i][j] != '*') {
                                        if (p[i - 1][j - 1] == '*') sum += 1;
                                        if (p[i - 1][j] == '*') sum += 1;
                                        if (p[i - 1][j + 1] == '*') sum+=1;
                                        if (p[i][j - 1] == '*') sum += 1;
                                        if (p[i][j + 1] == '*') sum += 1;
                                        if (p[i + 1][j - 1] == '*') sum += 1;
                                        if (p[i + 1][j ] == '*') sum += 1;
                                        if (p[i + 1][j + 1] == '*') sum += 1;

                                        if ( sum == 0) p[i][j] = '.';
                                        else p[i][j] = sum + 48;  
                                }
                            }
                            }
                            printf("Массив :\n");
                            
                            for ( unsigned j = 0; j < n + 2; j++){
                                for (unsigned k = 0; k < m + 2; k++){
                                    printf("%3c ", p[j][k]);
                                }
                                printf("\n");  
                            }
                            

                            for (int i = 0; i < n; i++) {   
                                    free(p[i]);  
                            }
                            free(p);
                            p = NULL;

                        break;
                }
                break;
                }
            continue;
        }
        printf("Неверный формат ввода.");
    }
    
  

}
