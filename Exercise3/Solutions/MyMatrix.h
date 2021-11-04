#pragma once

#include "MyMatrixOp.h"
#include <iostream>
#include <string>


class MyMatrix
{

public:
	MyMatrix();
	MyMatrix(int n, int m);
	MyMatrix(const MyMatrix & other);//copy constructor
	~MyMatrix();

	friend std::ostream& operator<<(std::ostream& os, const MyMatrix& mat);//operator that prints the values of the matrix
	
	friend std::istream& operator>>(std::istream& is, MyMatrix& mat);//operator that sets the values of the matrix from the user

	MyMatrix& operator=(const MyMatrix& mat);// operator that sets one matrix to other one
	
	bool operator==(const MyMatrix& mat) const;//checks if 2 matrixes are eaqual
	
	operator double const () const;// casting operator that returns sum of the values of the matrix

	const MyMatrix operator+(const MyMatrix& mat) const;//operator that sums 2 matrixes

	const MyMatrix operator-(const MyMatrix& mat) const;//operator that subs 2 matrixes
	
	const MyMatrix operator*(double num) const;

	friend const MyMatrix operator*(double num, MyMatrix& mat);

	const MyMatrix operator*(int num) const;

	friend const MyMatrix operator*(int num, MyMatrix& mat);

	const MyMatrix operator*(const MyMatrix& mat) const;

	MyMatrixOp operator[](int input1);// operator that returns the num in cell i,j in the format A[i][j]

private: 
	void Allocate(int n, int m);


private:
	double* _array = nullptr;
	int _n, _m;


};

