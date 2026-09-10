// arcsin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include  <cmath>
using namespace std;

int main() {
	double x, e;
	cout << "Enter your x: ";
	cin >> x;
	if (fabs(x) > 1) { return 1; }; // you must enter value between [-1; 1]
	cout << "Enter your eps (EX:0.0001): ";
	cin >> e;
	if (fabs(e) >= 1 && fabs(e) <= 0) { return 2; };//you must enter value between (1; 0)

	double k_n = x;
	double result = x;
	int k = 0;

	while (fabs(k_n) > e) {
		double chisl = (2. * k + 1.) * (2. * k + 1.) * x*x;
		double znam = (2.* k + 2.) * (2. * k + 3.);
		k_n = k_n * (chisl / znam);
		result = result + k_n;
		k = k + 1;
	}

	cout << "your result (pi = 3.14159236...): " << result << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
