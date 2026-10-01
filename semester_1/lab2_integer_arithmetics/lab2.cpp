
#include <iostream>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::swap;

bool contB(int x) //Bool-функция, которая будет проверять повторение цифер
{
    if (x < 0) x = -x;
    for (int i = 0; i < 10; i++)
    {
        int y = x; //переменная, которая будет меняться в процессе выполнения
        short kounter = 0;
        while (y > 0)
        {
            if (y % 10 == i) kounter++;
            y /= 10;
        }
        if (kounter > 1) return 0; //false - цифры числа повторяются
    }
    return 1;
}

void easy(int c)
{
    bool is_prime = true;
    if (c < 2) is_prime = false;
    else
    {
        for (int i = 2; i <= sqrt(c); i++){   // число простое с 2 (а по факту с 3)
            if (c % i == 0){
            is_prime = false;
                break;
            }
        }
    }

    if (is_prime && contB(c))
    {
        std::cout << "\033[38;2;50;205;50m" << c << " \033[0m"; //зеленым - искомые числа
    }
    else
    {
        cout << "\033[38;2;160;160;160m" << c << " \033[0m"; //серым обозначим сложные числа
    }
}

void z8()
{
    double a, b;
    int ai, bi; //a_integer;b_integer

    cout << "Введите a:\n";
    cin >> a;
    cout << "Введите b:\n";
    cin >> b;

    if (a > b) swap(a, b); //Нормальный промежуток: b>=a

    ai = a;
    bi = b;

    for (int i = ai; i <= bi; i++)
    {
        easy(i); //перебор всех чисел промежуток (интеджеров)
    }
    cout << endl;
}

int main()
{
    setlocale(0, "");
    z8();
    return 0;
}
