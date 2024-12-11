#include <iostream>

int IncorrectInput()
{   
    int a;
     while (!(std::cin >> a) || (std::cin.peek() != '\n')) // cin.peek() возвращает целочисленное представление следующего символа в буфере потока, не прочитав его
     {
        std::cin.clear(); //очищаем cin, приводим его в рабочее состояние
        while (std::cin.get() != '\n') //Читаем всю оставшуюся строку посимвольно(т.е. пока не встретим '\n')
        { }
        return 0;
        
     }
     
    
    return a;
}
double IncorrectInputDouble()
{   
    char incorrect = 'a';
    double a;
     while (!(std::cin >> a) || (std::cin.peek() != '\n')) // cin.peek() возвращает целочисленное представление следующего символа в буфере потока, не прочитав его
     {
        std::cin.clear(); //очищаем cin, приводим его в рабочее состояние
        while (std::cin.get() != '\n') //Читаем всю оставшуюся строку посимвольно(т.е. пока не встретим '\n')
        { }
        return incorrect;
     }
     

    return a;
}

int main( )
{
       std:: cout << " Пользователю необходмо ввести числа m и n. Такие что N - количество  столбцов M - Количество строк в матрице."
                  << " Программа определяет количество отрицатльных элементов, расположенных ниже побочной диагонали матрицы."
                  << "\nПрограмма выполнена Саранцевой Дарьей, учащейся группы 453502\n";


      for (int i = 0; i < 10; i++)
      {
         std::cout<<"*********";
      }
 

    while (true) {
      std::cout<<"\nВведите 1, если хотите начать программу, введите 2, если хотите закончить программу.\n";
      int status = IncorrectInput();

      if ( status !=1 && status !=2 ) {
        std:: cout << "Неверный формат ввода.";
        continue;
      }

      if ( status == 2 ){ 
        break;
      }


        while (true) {
            std::cout<<"Введите натуральное число N - количество строк матрицы. ";
            int N = IncorrectInput();
            if( N <= 0){
              
                    std:: cout << "Неверный формат ввода. Введите натуральное число.\t";
                    continue;
                
            }
            while (1)
            {
            
                
                std::cout<<"Введите натуральное число M - количество столбцов матрицы. Количество столбцов не меньше чем количество строк. ";

                int M = IncorrectInput();
                if( M <= 0 || M < N){
                
                        std:: cout << "Неверный формат ввода. Введите натуральное число.\t";
                        continue;
                    
                }
                
                const int row = N, col = M;
                double matrix[row][col] = {0};

                for (int i = 0; i < row; i++){
                    for(int j = 0; j < col; j++){
                        matrix[i][j] = -50 + rand()%100;
                    }
                }

                int sum = 0;
                for ( int i = 1; i < row; i++) {
                    for( int j = 0; j < col; j++ ){
                        if( ( (i + j) > row - 1) && ( matrix[i][j] < 0)){
                            sum++;
                        }
                    }
                }
                
                

                std::cout<< "Исходный массив:\n";
                for ( auto &submatrix : matrix) {
                    for( double matrix : submatrix){
                        std::cout<<matrix<< '\t';
                    }
                    std::cout<<'\n';
                }

                std::cout<<"Количество отрицатльных элементов матрицы, расположенных ниже побочной оси: "<<sum<<'\n';
            
                break;
            }
        break;
        }
  
    }
}


