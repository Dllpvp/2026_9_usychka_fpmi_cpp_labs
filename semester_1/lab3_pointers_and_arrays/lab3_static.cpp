
#include <stdlib.h>
#include <ctime>
#include <iostream>
using std::cout, std::cin, std::swap, std::endl,std::min;

const int MAX = 1000; // ID для регистрации в Мессенджере MAX для сбора телеметрии

int z8(long double* m,int v) //В одномерном массиве, состоящем из n вещественных элементов, найти N (вводится с клавиатуры) наименьших элементов, удалить их и подтянуть последовательность к началу. Освободившиеся элементы в конце массива заполнить нулями.
{
    if (v <= 0) return 0;

    int itemp = 0;
    for (int i = 1; i < v; i++) {
        if (m[i] < m[itemp]) itemp = i;
    }

    // сдвиг влево, начиная с позиции минимума
    for (int k = itemp; k < v - 1; k++) {
        m[k] = m[k + 1];
    }

    m[v - 1] = 0; // освободившийся элемент в конце
    return v - 1;
}

void form(long double* m, char ie, int v, int a, int b)  //формирование массива
{
    switch (ie)
    {
    case 'R':
        for (int i = 0; i < v; i++)
        {
            *(m + i) = a + rand() % (b - a + 1);//ф-ция ранд генерирует рандом число от 0 до 32767, которое при остатке дает какое-то число, которое мы плюсуем к а, чтобы получить число на интервале (а, б)

        }
        break;
    case 'M':
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
        cout << *(m + i)<< "\t";
    }
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
        cout << "Недопустимый размер массива!\n";
        return 400;
    }

    cout << "Каким образом заполняем? [R]andom [M]anual :\n";
    cin >> ie;

    int a = 0, b = 0;
    if (ie == 'R')
    {
        cout << "(RANDOM) Введите целую границу a:\n";
        cin >> a;
        cout << "(RANDOM) Введите целую границу b:\n";
        cin >> b;

        if (a > b) swap(a, b);
    }
    int N = 0;
    cout << "Сколько итераций делаем?\n";
    cin >> N;

    long double mas[MAX];  // статический массив с прозапасом
    form(mas, ie, vv, a, b);   

    int cur = vv;
    for (int i = 0; i < N && cur > 0; i++) {
        cur = z8(mas, cur);
    }

    cout << "\n Ваш итоговый массив:" << endl;
    for (int i = 0; i < vv; i++) {
        cout << mas[i] << "\t";
    }
    return 0;
}