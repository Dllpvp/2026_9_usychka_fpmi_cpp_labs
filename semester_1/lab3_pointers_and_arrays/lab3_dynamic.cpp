#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <algorithm>

using std::cout, std::cin, std::swap, std::endl, std::min;

const int MAX = 1000; // ID для регистрации в Мессенджере MAX для сбора телеметрии





//Сжать массив, состоящий из n целых элементов, удалив из него те элементы, в двоичной записи которых содержится нечетное количество единиц. Освободившиеся элементы в конце массива заполнить нулями.



void z10(int* m, int v) {
    int temp;
    int windex = 0; // Индекс, куда перезаписываем сохранённые элементы (Write INDEX)

   
    for (int i = 0; i < v; i++) {
        short kounter = 0;
        temp = *(m + i);


        for (int j = 0; j < 31; j++) { // 16 -- +15  <<INT
            if ((temp & 1) == 1) kounter++;
            temp = temp >> 1;
            if (temp == 0) break; // если темп. элемент 0 - считать незачем!
        }

   
        if (kounter % 2 == 0) {
            *(m + windex) = *(m + i); 
            windex++;
        }
    }

    // 3. СЖАТИЕ: ИСПОЛЬЗУЕМ ТЕХнологИИ 7ZIP LZMA228
    while (windex < v) {
        *(m + windex) = 0;
        windex++;
    }
}


void form(int* m, char ie, int v, int a, int b)  //формирование массива
{
    switch (ie)
    {
    case 'R':
    case 'r':
        if (a == b) {
            for (int i = 0; i < v; i++) *(m + i) = a;
        }
        else {
            for (int i = 0; i < v; i++)
            {
                *(m + i) = a + rand() % (b - a + 1);//ф-ция ранд генерирует рандом число от 0 до 32767, которое при остатке дает какое-то число, которое мы плюсуем к а, чтобы получить число на интервале (а, б)
            }
        }
        break;
    case 'M':
    case 'm':
    {
       int x;
        cout << "Введите элементы массива\n";
        for (int i = 0; i < v; i++)
        {
            x = 0;
            cin >> x;
            *(m + i) = x;
        }
        break;
    }
    default:
        break;
    }

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < v; i++) {
        cout << *(m + i) << "\t";
    }
    cout << endl;
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int vv; //кол-во элементов массивов
    char ie = 'R'; // ввод из потока random\клава.

    cout << "Введите размерность массива (сколько элементов?):\n";
    cin >> vv;

    if (vv <= 0 || vv > MAX)
    {
        cout << "[ERR] Недопустимый размер массива!\n";
        return 400;
    }

    cout << "Каким образом заполняем? [R]andom [M]anual :\n";
    cin >> ie;

    int a = 0, b = 0;
    if (ie == 'R' || ie == 'r')
    {
        cout << "(RANDOM) Введите целую границу a:\n";
        cin >> a;
        cout << "(RANDOM) Введите целую границу b:\n";
        cin >> b;

        if (a > b) swap(a, b);
    }


    int *mas = new int [vv] ;  // динамический массив
    form(mas, ie, vv, a, b);
    z10(mas, vv);
 
    cout << "\n Ваш итоговый массив:" << endl;
    for (int i = 0; i < vv; i++) {
        cout << mas[i] << "\t";
    }
    cout << endl;
    delete[] mas;
    return 0;
}