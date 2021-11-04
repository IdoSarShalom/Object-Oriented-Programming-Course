#include "Complex.h"
#include <math.h>
#include <iostream>	
using namespace std;

//default constructor 
Complex::Complex()
{
}

//complex number constructor 
Complex::Complex(int real, int imaginary)
{
	this->_real = real;
	this->_imaginary = imaginary;
}

//Copy constructor 
Complex::Complex(const Complex &complex)
{
	this->_real = complex.getReal();
	this->_imaginary = complex.getImaginary();
}


//default destructor
Complex::~Complex()
{
}

int Complex::getReal() const
{
	return this->_real; 
}

int Complex::getImaginary() const
{
	return this->_imaginary;
}

//set all the data members  
void Complex::setRealAndImaginary(int real,int imaginary) 
{
	this->_real = real;
	this->_imaginary = imaginary; 
}

	
//the absolute value of the complex number
double Complex::getAbsoluteValue() const
{
	return (double)sqrt(pow(this->_real, 2) + pow(this->_imaginary, 2));
}

double Complex::getPhase() const
{
	return (double)atan2(this->_imaginary, this->_real);
}

Complex Complex::add(Complex complex1) const
{
	Complex complex2((int)(this->_real + complex1.getReal()), (int)(this->_imaginary + complex1.getImaginary()));
	return complex2;
}

Complex Complex::sub(Complex complex1) const 
{
	Complex complex2((int)(this->_real - complex1.getReal()), (int)(this->_imaginary - complex1.getImaginary()));
	return complex2;
}

void Complex::print() const 
{
	cout << getReal() << " + " << getImaginary() << "i (" << getAbsoluteValue() << "," << getPhase() << ")" << endl;
}