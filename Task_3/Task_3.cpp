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
       std:: cout << " Пользователю необходмо ввести число N. Такое что N - количество  столбцов и строк в матрице."
                  << " Программа находит максимальный и минимальный элементы. Переставляет строки, в которых они находятся."
                  << " Если они находятся в одной строке, выдаёт об этом сообщение."
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
            std::cout<<"Введите натуральное число N - количество строк и столбцов матрицы. ";
            int N = IncorrectInput();
            if( N <= 0){
              
                    std:: cout << "Неверный формат ввода. Введите натуральное число.\t";
                    continue;
                
            }
            
           
            double** matrix = new double*[N]; //строки
            for( int i = 0; i < N; i++){
                matrix[i] = new double[N];
            }

            for( int i = 0; i < N; i++){
                for( int j = 0; j < N; j++){
                  matrix[i][j] = -100 + rand() % 200;
                }
            }

            int max = *(matrix[0] + 0), min = *(matrix[0] + 0), strmax = 0, strmin = 0;

            for( int i = 0; i < N; i++){
                for( int j = 0; j < N; j++){
                    if ( matrix[i][j] > max)
                    {
                        max = matrix[i][j];
                        strmax = i;
                    }
                     if ( matrix[i][j] < min)
                    {
                        min = matrix[i][j];
                        strmin = i;
                    }
                    
                }
            }

            std::cout<<"Изначальная матрица:'\n";
            for( int i = 0; i < N; i++){
                for( int j = 0; j < N; j++){
                  std::cout<<matrix[i][j]<<" ";
                }
                std::cout<<'\n';
            }

            if( strmin == strmax){
                std::cout<<"Минимальный и максимальный элементы находятся в одной строке("<<strmin<<")";
            }
            else{

            for (int i = 0; i < N; i++)
            {
                double a = matrix[strmin][i];
                matrix[strmin][i] = matrix[strmax][i];
                matrix[strmax][i] = a;
            }
            

            std::cout<<"Преобразованная матрица:'\n";
            for( int i = 0; i < N; i++){
                for( int j = 0; j < N; j++){
                  std::cout<<matrix[i][j]<<" ";
                }
                std::cout<<'\n';
            }
            }

            for( int i = 0; i<N; i++){
                delete[] matrix[i];
                matrix[i] = nullptr;
            }
            delete[] matrix;
            matrix = nullptr;
          
            break;

        }
    
    }
}
