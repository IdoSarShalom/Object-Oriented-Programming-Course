#pragma once

#include <iostream>
#include <string>


class MyMatrixOp
{
private:
	double * _array;
	int _input1;
	int _columns;

public:
	MyMatrixOp();
	MyMatrixOp(int input1, int columns,double * array);
	double& operator[](int input2);
	~MyMatrixOp();
};

