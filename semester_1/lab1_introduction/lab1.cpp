// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void z1()
{
    int m, n;
    cout << "\n Enter natural nums::";

    cin >> m >> n;
    cout << "\n Args:" << m << ' ' << n;
    int minimum = min(m, n);
    cout << "\n OK \n";
    for (int i = 2; i <= minimum; i++) {
        if (m % i == 0 && n % i == 0) {

            cout << i << endl;
        }

    }



}

void z2(){}


int main()
{
    int ie = 0;
    cout << "Enter your number of task:: ";
    cin >> ie;
    switch (ie) {
    case 1:
        z1();
        break;
    case 2:
        z2();
        break;

    }

}

