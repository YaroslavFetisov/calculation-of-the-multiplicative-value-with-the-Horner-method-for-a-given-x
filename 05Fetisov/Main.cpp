#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

void fillArray(double*, size_t);
double Horner(double*, size_t, double);
double sum(double*, size_t, int);
double HornerTest(double*, size_t, double);

int main(void) {
	int size = 5;
	double* coeff = new double[size];
	for (int i = -10; i <= 10; ++i) {
		int x = i;
		fillArray(coeff, size);
		for (int i = 0; i < size; i++)
		{
			if (i != size - 1)
				cout << coeff[i] << " * " << x << "^" << (size - i - 1) << " + ";
			else
				cout << coeff[i];
		}
		cout << " = " << Horner(coeff, size, x) << endl;
		cout << "Test: " << HornerTest(coeff, size, x) << endl;
		cout << "The sum of the coefficients: " << sum(coeff, size, x) << endl;
		cout << "------------------------------------------" << "\n" << endl;
	}

	return 0;
}


void fillArray(double* coeff, size_t size) {
	for (int i = 0; i < size; i++) {
		int s = rand() % 1;
		int sign;
		// 0(-) 1(+)
		if (s == 0) {
			sign = -1;
		}
		else {
			sign = 1;
		}
		coeff[i] = (rand() % 1000 + static_cast<double>((rand() % 100)) / 100);
	}
}

double sum(double* coeff, size_t size, int sign){
	double sum = 0;
	if (sign == -1) {
		if (size % 2 == 0) {
			for (int i = 0; i < size; i++)
			{
				sum += coeff[i] * sign;
				sign *= -1;
			}
		}
		else {
			for (int i = 0; i < size; i++)
			{
				sum += coeff[i] * sign * -1;
				sign *= -1;
			}
		}
	}
	else {
		for (int i = 0; i < size; i++)
		{
			sum += coeff[i];
		}
	}

	return sum;
}

double Horner(double* coeff, size_t size, double x){
	double result = 0;
	result = coeff[0];

	for (int i = 1; i < size; ++i) {
		result = result * x + coeff[i];
	}
	assert(((x == 1) || (x == -1)) ? (result == sum(coeff, size, int(x))) : true);

	return result;
}

double HornerTest(double* coeff, size_t size, double x){
	double result = 0;

	for (int i = 0; i < size; i++) {
		result += coeff[i] * pow(x, size - i - 1);
	}

	return result;
}