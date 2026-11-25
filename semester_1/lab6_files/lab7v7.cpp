#include <iostream>
#include <string>
#include <Windows.h>

#include <fstream>
#include <chrono>


//Вариант 7
using std::cout, std::cin, std::endl, std::string;

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format
        ? std::put_time(std::gmtime(&time), "%x %X")
        : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}


int main()
{
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    SetConsoleCP(1251);
    std::ofstream Log("latest.log", std::ios::out | std::ios::trunc);
    if (!Log) {
        std::cerr << "Мы не можем открыть лог...";
        return 3;
    }

    Log << '[' << FormatTime(Now(), false) << "] " << "Открываем INPUT.TXT... " << endl;
    std::ifstream fin("INPUT.TXT");
    if (!fin) {
        Log << '[' << FormatTime(Now(), false) << "] " << "Мы не можем открыть INPUT.txt." << endl;
        Log << '[' << FormatTime(Now(), false) << "] " << "Программа завершена с кодом 1." << endl;
        return 1;
    }
    Log << '[' << FormatTime(Now(), false) << "] " << "Успех! " << endl;
    Log << '[' << FormatTime(Now(), false) << "] " << "Открываем OUTPUT.TXT... " << endl;
    std::ofstream fout("OUTPUT.TXT");
    if (!fout) {
        Log << '[' << FormatTime(Now(), false) << "] " << "Мы не можем открыть OUTPUT.txt." << endl;
        Log << '[' << FormatTime(Now(), false) << "] " << "Программа завершена с кодом 2." << endl;
        return 2;
    }
    Log << '[' << FormatTime(Now(), false) << "] " << "Успех! " << endl;







    Log << "[" << FormatTime(Now(), false) << "] " << "Ищем строку в INPUT.TXT... " << endl;
    string str;
    getline(fin, str);

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
    Log << '[' << FormatTime(Now(), false) << "] " << "RLE cтрочка успешно сгенерирована! " << endl;
    fout << str << endl;
    Log << '[' << FormatTime(Now(), false) << "] " << "RLE cтрочка успешно записана в OUTPUT! " << endl;

    fin.close();
    fout.close();
    Log << '[' << FormatTime(Now(), false) << "] " << "Программа завершилась с кодом 0. Успешный успех :)" << endl;
    Log.close();
    return 0;
}