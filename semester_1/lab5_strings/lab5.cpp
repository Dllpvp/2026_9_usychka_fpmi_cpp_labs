#include <iostream>
#include <string>
#include <Windows.h>
using std::cout, std::cin, std::endl, std::string;

int main()
{
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    SetConsoleCP(1251);

    cout << "Введите вашу строку: " << endl;
    string str;
    getline(cin, str);

    cout << endl;

    unsigned int i = 0;
    while (i < str.size()) {
        unsigned int a = 1;
     
        while (i + a < str.size() && str[i] == str[i + a]) {
            a++;
        }
        if (a > 1) {
            str.replace(i, a, str[i] + std::to_string(a));
            i++;  
        }
        else i++;  
    }

    cout << "Ваша RLE строченька: " << str << endl;
}