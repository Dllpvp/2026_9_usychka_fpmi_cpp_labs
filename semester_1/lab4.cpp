// VARIANT 8
//Создать новую матрицу S n × m (матрица префиксных сумм), в которой каждый элемент s i j равен сумме всех элементов исходной матрицы A n × m , лежащих в прямоугольнике от ( 0 , 0 ) до ( i , j ) . Вывести матрицы A и S на экран.
#include <cstdlib>
#include <iostream>
#include <iomanip>
using std::cin, std::cout, std::endl, std::swap, std::cerr;

void Print(int** mas, int n, int m) { //печать массива
    for (int i = 0;i < n;i++) {
        cout << endl;
        for (int j = 0;j < m;j++) {
            cout << std::setw(6) << *(*(mas + i) + j) << " ";
        }
    }

}




void Fill(int** mas, char ch, int n, int m) { //Заполнение исходного массива
    switch (ch) {
    case 'R':
        cout << "Enter the limits of RandGen: " << endl;
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);


        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                *(*(mas + i) + j) = a + rand() % (b - a + 1);
            }
        }
        break;

    case 'M':
        cout << "Enter your values: " << endl;

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                cin >> *(*(mas + i) + j);
            }
        }
        break;

    default:
        cerr << "Unable to enter values.. " << endl;
    }
    cout << "Your MATRIX: \n";
    Print(mas, n, m);

}




int SumI(int** mas, int i, int j) {
    int g = 0;
    for (int it = 0;it <= i;it++) { //iterator
        for (int jt = 0;jt <= j;jt++) { //jterator 
            g += *(*(mas + it) + jt);
        }
    }
    return g; //summa vseh elementov s 0 do i,j
}


void Pref(int** mas, int** maS, int n, int m) { //тут вычисление сумм ячеек для нового массива
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            *(*(maS + i) + j) = SumI(mas, i, j);
        }
    }
    cout << "\n Your NEW MATRIX: \n";
    Print(maS, n, m);
}


int main()
{
    srand(time(NULL));
    cout << "enter number N columns: " << endl;
    int n;
    cin >> n;

    cout << "enter number M rows: " << endl;
    int m;
    cin >> m;

    int** mas;
    mas = new int* [m];
    for (int i = 0; i < m; i++) {
        mas[i] = new int[n];
    }

    int** maS;
    maS = new int* [m];
    for (int i = 0; i < m; i++) {
        maS[i] = new int[n];
    }
    char ch;
    cout << "How we will form this matrix? [R]andom [M]anual?";
    cin >> ch;

    Fill(mas, ch, m, n);
    Pref(mas, maS, m, n);

    for (int i = 0; i < m; i++)
        delete[] mas[i];
    delete[] mas;

    for (int i = 0; i < m; i++)
        delete[] maS[i];
    delete[] maS;
}

