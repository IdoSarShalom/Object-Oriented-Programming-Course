#pragma once
class Complex
{
private:	
	int _real;
	int _imaginary; 



public:
	Complex(); //default constructor 
	Complex(int real, int imaginary); //complex number constructor 
	Complex(const Complex &complex); //copy constructor 

	~Complex(); //default destructor 
	

	int getReal() const; //the function can not change the data members 
	int getImaginary() const;
	void setRealAndImaginary(int real,int imaginary);
	double getAbsoluteValue() const;
	double getPhase() const;
	Complex add(Complex complex1) const;
	Complex sub(Complex complex1) const;
	void print() const;



};

