#include <iostream>
#include <cmath>

float f(float x1, float x2) { //������� �������
	return pow(x1 - 2, 2) + pow(x2 - 3, 2);
}

float h(float x1, float x2) { //�����������
	return x1 + x2 - 8;
}

float R(float x1, float x2) { // ������� ������ ���� �������� �������
	return 1 / (h(x1, x2));
}

float Z(float x1, float x2, float r) { // ������� �� ������ �������� ����������� � ������ ����������� �����������
	return f(x1, x2) + r * R(x1, x2);
}

int main() {
	float x1 = 0, x2 = 0;
	float P, Z_def, Z;
	float r=2, b=0.5, e=0.01, h=0.1;
	P = r * (1/x1+x2-8);  // O���� ������� ������ � ���������������� ������ ���� �������� �������
	Z = pow(x1 - 2, 2) + pow(x2 - 3, 2) + r * (1 / x1 + x2 - 8);

	system("pause");
	return 0;
}