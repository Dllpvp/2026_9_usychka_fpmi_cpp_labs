
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::swap;




void easy(int c) {

	for (int i = 2; i <= sqrt(c); i++) // число простое с 2 (а по факту с 3).
		if (c % i == 0) {
			cout << "[38;2;160;160;160m" << c << " [0m"; //серым обозначим сложные числа
			return;
		}
	std::cout << "[38;2;50;205;50m" << c << " [0m"; //зеленым - искомые числа
}


void z8() {
	double a, b;
	int ai, bi;//a_integer;b_integer

	cout << "Введите a:\n";
	cin >> a;
	cout << "Введите b:\n";
	cin >> b;
	if (a > b) 
		swap(a, b); //Нормальный промежуток: b>=a
	ai = a;
	bi = b;
	for (int i = a; i <= b; i++) {
		easy(i); //перебор всех чисел промежуток (интеджеров)
	}
}


int main()
{
	setlocale(0, "");
	z8();

	return 0;
}
