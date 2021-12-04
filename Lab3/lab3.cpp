#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

long double f(double x1, double x2); //Function
void HookJeeves_method(); //Hook Jeeves method

long double x[] = { 3, 2 }, increment[] = { 2.5, 3 }, x_last[] = { 3, 2 }, xtemp[2] = { 0 };
int a = 2;
bool changed = false;
long double func, eps = 0.0001;

int main() {

	HookJeeves_method();

	system("pause");
	return 0;
}
		
long double f(long double x1, long double x2) {
	return pow(x1, 2) + x1 * x2 + pow(x2, 2) - 6 * x1 - 9 * x2;
}

void HookJeeves_method() { 
		
	while (true) 
	{
		//"Exploring" search
		func = f(x[0], x[1]); //Base point
		if (f(x[0] + increment[0], x[1]) < func)  {x[0] += increment[0]; changed = true;}
		if (f(x[0], x[1] + increment[1]) < func)  {x[1] += increment[1]; changed = true;}
		if (changed == false) 
		{
			if (f(x[0] - increment[0], x[1]) < func)  {x[0] -= increment[0]; changed = true;}
			if (f(x[0], x[1] - increment[1]) < func)  {x[1] -= increment[1]; changed = true; }
		}
		//Pattern search
		if (changed == true) 
		{
			changed = false;
			while (true)
			{
				xtemp[0] = x[0] + (x[0] - x_last[0]);
				xtemp[1] = x[1] + (x[1] - x_last[1]);
				if (f(xtemp[0], xtemp[1]) < f(x[0], x[1]))
				{
					x_last[0] = x[0];
					x_last[1] = x[1];
					x[0] = xtemp[0];
					x[1] = xtemp[1];
				}
				else break;
			}
		}
			if (sqrt(pow(increment[0], 2) + pow(increment[1], 2)) > eps)
			{
				increment[0] /= a;
				increment[1] /= a;
			}
			else break; //exit
	}
	cout.setf(ios::floatfield, ios::fixed);
	cout << "HookJeeves method: x(" << x[0] << ", " << x[1] << ")   " << "F(x)= " << f(x[0], x[1]) << "   |delta x|=" << sqrt(pow(increment[0], 2) + pow(increment[1], 2)) <<"<"<< eps << endl;
	return;
}
