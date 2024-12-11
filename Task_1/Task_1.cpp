#include <iostream>

void sort(long double arr[], int l, int r) ;

void merge(long double arr[], int l, int m, int r);

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
       std:: cout << "Пользователю необходимо вести k чисел в одномерный статический массив.\nПрограмма выполняет преобразовагия массива следующим образом:"
                  << " все отрицательные элементы массива перенести в начало, сохранив исходное взаимное расположение,"
                  << " как среди отрицательных, так и среди остальных элементов массива."
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
            std::cout<<"Введите натуральное число k, которое обозначает из скольки элементов бyдет состоять массив.";
            int k = IncorrectInput();

            if( k <= 0){
               
                    std:: cout << "Неверный формат ввода. Введите натуральное число.\t";
                    continue;
                
            }
            int size = k;
            long double array[size];
            std::cout<< "Необходимо ввести " << size << " элементов, где все элементы являются числами.\n";
            for (int i = 0; i < size; ) {   
                std::cout<< "Введите " << i + 1 << " элемент\n";

                double input = IncorrectInputDouble();
               
                if ( input == 'a') {
                    std:: cout << "Неверный формат ввода. Введите число.\n";
                    
                    continue;
                }
                
                array[i] = {input};
                ++i;
             }
    
            std::cout<< "Исходный массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout<< "array[" << i <<"] = " << array[i] << "\n";
            }

            sort( array, 0, size-1 );

             std::cout<< "Преобразованный массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout<< "array[" << i <<"] = " << array[i] << "\n";
            }  
       break;

        }
    break;
    }
}



void merge(long double arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if ((L[i] >= 0) && ( R[j] < 0)) {
            arr[k] = R[j];
            j++;
        } else {
            arr[k] = L[i];
            i++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void sort(long double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

