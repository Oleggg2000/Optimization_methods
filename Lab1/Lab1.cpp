#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double f(double z); //Функция
void Dichotomy_method(); // Метод дихотомии
void Golden_ratio(); //Метод золотого сечения

double a = -2.0, b = 3.0, e = 0.0009, h = 0.001, x;


void main()
{
	Dichotomy_method();
	cout << endl;
	Golden_ratio();

	system("pause");
	return;
}

double f(double z) { //Функция
	return 10 * pow(z, 3) + 3 * pow(z, 2) + z + 5;
	//return pow(z, 3) - x + 1;
}

void Dichotomy_method() { // Метод дихотомии
	double y, z;

	while (abs(b - a) >= e)
	{
		y = (a + b - h) / 2;
		z = (a + b + h) / 2;

		if (f(y) <= f(z)) b = y;
		else a = z;
	}

	x = (a + b) / 2;
	cout << "x= " << x << "\nF(x)= " << f(x) << "\n|a-b|= " << abs(a - b) << endl;
}

void Golden_ratio() { //Метод золотого сечения
	double y, z;

	y = a + (3 - sqrt(5)) / 2 * (b - a);
	z = a + b - y;

	while (abs(b - a) >= e)
	{
		if (f(y) <= f(z)) {
			b = z;
			y = a + b - y;
			z = y;
		}
		else {
			a = y;
			y = z;
			z = a + b - z;
		}
	}

	x = (a + b) / 2;
	cout << "x= " << x << "\nF(x)= " << f(x) << "\n|a-b|= " << abs(a - b) << endl;
}