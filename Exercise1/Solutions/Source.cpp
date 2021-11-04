#include "Complex.h"
#include <math.h>
#include <iostream>
using namespace std;


int main()
{
	Complex complex1;
	complex1.setRealAndImaginary(1, 1);	
	complex1.print();
	int x;
	x = complex1.getReal();
	cout << x << endl;
	x = complex1.getImaginary();
	cout << x << endl;
	double y;
	y = complex1.getAbsoluteValue();
	cout << y << endl;
	y = complex1.getPhase();
	cout << y << endl;
	Complex complex2(2, 4);
	Complex complex3;
	complex3 = complex1.add(complex2);
	complex3.print();
	Complex complex4(complex3); //using copy constructor 
	complex4.print();


	system("pause");
}