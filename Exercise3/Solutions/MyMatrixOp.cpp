#include "MyMatrixOp.h"


MyMatrixOp::MyMatrixOp()
{
}

MyMatrixOp::MyMatrixOp(int input1,int columns, double * array)
{
	_input1 = input1;
	_columns = columns;
	_array = array;
}

double& MyMatrixOp::operator[](int input2)
{
	if (input2 < 0 || input2 > _columns - 1)
		throw "out of bounds matrix dimensions";
	int index =  _input1 * _columns + input2;
	return _array[index];
}


MyMatrixOp::~MyMatrixOp()
{
}
