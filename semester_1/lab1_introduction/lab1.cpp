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
	cout << "\n1\n";
	for (int i = 2; i <= minimum; i++)
	{
		if (m % i == 0 && n % i == 0)
		{

			cout << i << endl;
		}

	}



}


void z2()
{
	unsigned long int n = 0;
	unsigned long int m = 0;
	cout << "\nEnter N (N>0):: ";
	cin >> n;
	if (n <= 0) {
		cout << "N must be >0" << endl;

	}
	else {
		m = n * n; //T.K.  1+3+5+..+2k-1=k^2
		cout << endl << m << endl;

	}




}
void z3() {
	char a, b, c, d;
	cout << "Enter your natural number (XXXX):";
	cin >> a >> b >> c >> d;
	cout << a << b << c << d;
	if ((!(a >= 48 && a <= 57 && b >= 48 && b <= 57 && c >= 48 && c <= 57 && d >= 48 && d <= 57)) || (a == 48 && b == 48 && c == 48 && d == 48)) { //0 - 0x48, 9 - 0x57,  -  проверка на то, что это цифры
		cout << "\nThis is not natural number!\n";	//Нотация: число 0000 мы тут не считаем "Натуральным"

	}
	else {
		if (a == d && b == c) {
			cout << "\nPolynom!";
		}
		else {
			cout << "\nNot polynom!";
		}
	}
}
void z4() {
	char a, b, c, d, e, f;
	cout << "Enter your natural number (XXXXXX):";
	cin >> a >> b >> c >> d >> e >> f;
	cout << a << b << c << d << e << f;
	if ((!(a >= 48 && a <= 57 && b >= 48 && b <= 57 && c >= 48 && c <= 57 && d >= 48 && d <= 57 && e >= 48 && e <= 57 && f >= 48 && f <= 57)) || (a == 48 && b == 48 && c == 48 && d == 48 && e == 48 && f == 48)) { //0 - 0x48, 9 - 0x57,  -  проверка на то, что это цифры
		cout << "\nThis is not natural number!\n";//Нотация: число 000000 мы тут не считаем "Натуральным"

	}
	else {
		int res1 = a - '0' + b - '0' + c - '0';//первая часть результата 
		int res2 = d - '0' + e - '0' + f - '0';//вторая часть результата
		if (res1 == res2) {
			cout << "\nSchastlivoye chislo!";
		}
		else {
			cout << "\nNe schastlivoye chislo!";
		}
	}
}
void z5() {
	short n = 0;
	cout << "Vvedite N (2>=N>91)::\n"; // Больше 91 вводить не стоит. пойдет переполнение
	cin >> n;
	if (n < 2) {
		cout << "Enter n>=2\n";

	}
	else {
		cout << "Chisla Fibonachi::\n";
		cout << "0\n";
		cout << "1\n";

		unsigned long long f, f1 = 1, f2 = 0; //- F_N, F_n-1, f_n-2 соотв.
		for (short i = 3; i <= n; i++) { //начнем с 3, т.к. первые 2 введены.
			f = f1 + f2;//следующее число фибоначи
			cout << f << endl;

			f2 = f1;
			f1 = f;

		}
	}

}
void z6() {
	int a, b, d, a0;
	cout << "Enter a::\n";
	cin >> a;


	cout << "Enter b::\n";
	cin >> b;

	cout << "Enter distance::\n";
	cin >> d;
	if (d > 0) {
		if (a > b) swap(a, b);// если промежуток задался к примеру не от 0 до 10 а от 10 до 0

		a0 = a;
		cout << "Your numbers::\n"; //промежуток со включением: [a;b]
		for (int i = a; i <= b; i += d) {
			if (i % 3 == 0) cout << i << endl;
			a0 += d;
		}
	}
	else {
		d = -d;
		if (a > b) swap(a, b);// если промежуток задался к примеру не от 0 до 10 а от 10 до 0

		a0 = a;
		cout << "Your numbers::\n"; //промежуток со включением: [a;b]
		for (int i = a; i <= b; i += d) {
			if (i % 3 == 0) cout << i << endl;
			a0 += d;
		}

	}


}
void z7() {
	int n;
	cout << "Enter n (1-7)::\n";
	cin >> n;

	int k;
	cout << "Enter k (1-99)::\n";
	cin >> k;
	if (n < 1 || n>7 || k < 1 || k>99) {
		cout << "An error in input data. Make sure that your data provides limits.\n";

	}
	else {
		cout << endl;
		for (int i = 0; i < 3 * n - 1; i++) { //методом экспериментов выяснили.Хотя это нетрудно подчитать
			cout << " ";
		}

		int counter = 1;
		cout << counter;
		counter++;
		for (int i = 0; i <= 7 - n - 1; i++) { // 7-n-1 т.к. у нас уже 1 символ - единица вставлен
			cout << " ";
			cout << " ";
			cout << counter;
			counter++;
		}



		for (int i = 0; i < (((k - (7 - n - 1)) / 7) + 1); i++) { //(((k - (7 - n - 1)) / 7) + 1) - число дней, которые мы ещё не записали в консолю (взято с запасом на 1, т.к. может быть ещё остаток)
			cout << endl;

			for (int i = 0; i < 7; i++) {
				if (counter > k) break;

				if (counter > 9) {
					cout << " ";
					cout << counter;
					counter++;
				}
				else {
					cout << " ";
					cout << " ";
					cout << counter;
					counter++;
				}

			}



		}


	}







}


int main()
{
	int ie = 0;
	cout << "Enter your number of task (1-7):: ";
	cin >> ie;
	switch (ie)
	{
	case 1:
		z1();
		break;
	case 2:
		z2();
		break;


	case 3:
		z3();
		break;

	case 4:
		z4();
		break;

	case 5:
		z5();
		break;

	case 6:
		z6();
		break;

	case 7:
		z7();
		break;
	}

	return 0;
}

