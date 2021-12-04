#include <iostream>
#include <cmath>
#include <cstdlib>

double eps = 0.0001, a = 1, b = 5, max_i = 999, z;

double Function(double X)
{
	return 2 * pow(X, 2) + (16 / X);
}

double derFunction1(double X)
{
	return 4 * X - 16 / pow(X, 2);
}

double derFunction2(double X)
{
	return 4 + 32 / pow(X, 3);
}

double derFunction3(double X)
{
	return -96 / pow(X, 4);
}


void Bolzano_method()
{
	std::cout << "Bolzano method: " << std::endl << std::endl;

	while (std::fabs(derFunction1(z)) > eps)
	{
		z = (a + b) / 2;

		if (derFunction1(z) < 0) a = z;
		else b = z;
	}

	std::cout.setf(std::ios::scientific);
	std::cout.precision(10);
	std::cout << "Root is: " << z << std::endl;
	printf("F(x)= %f", Function(z));
	//std::cout << "F(x) = " << Function(z) << std::endl << std::endl;
}

void Newton_Raphson_method()
{
	std::cout << std::endl << "Newton-Raphson method: " << std::endl << std::endl;

	double x0,
		f1 = derFunction1(a),
		f3 = derFunction3(a),
		h = derFunction1(z) / derFunction2(z);

	std::cout << "Enter guess x0: " << std::endl;
	std::cin >> x0;

	if (f1*f3 < 0) x0 = b;

	do
	{
		h = derFunction1(x0) / derFunction2(x0);

		x0 -= h;

	} while (std::abs(derFunction1(x0)) >= eps);

	std::cout.setf(std::ios::scientific);
	std::cout.precision(10);
	std::cout << std::endl << "Root is: " << x0 << std::endl;
	printf("F(x)= %f\n", Function(z));
	//std::cout << "F(x) = " << Function(x0) << std::endl << std::endl;
}


int main()
{
	Bolzano_method();

	Newton_Raphson_method();

	system("pause");
	return 0;
}

