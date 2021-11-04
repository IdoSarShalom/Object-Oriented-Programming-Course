#include "MyMatrix.h"

using namespace std; 


MyMatrix::MyMatrix() : MyMatrix(3,3)// default constructor
{
}

MyMatrix::MyMatrix(int n, int m)
{
	if (n <= 0 || m <= 0)
		throw "invalid values of the matrix dimensions";

	Allocate(n, m);

	for (int j = 0; j < _n * _m; j++)
		_array[j] = 0; 
}

MyMatrix::MyMatrix(const MyMatrix & other)//copy constructor
{
	Allocate(other._n, other._m);

	for (int i = 0;i < _n * _m; i++)
		_array[i] = other._array[i];
}

void MyMatrix::Allocate(int n, int m)// set the matrix to size n*m
{
	delete[] _array;
	_array = nullptr; 
	_n = n;
	_m = m;
	_array = new double[_n * _m];
}

MyMatrix::~MyMatrix()
{
	delete[] _array; 
	_array = nullptr;
}



MyMatrix& MyMatrix::operator=(const MyMatrix& mat)
{
	if (this != &mat)
	{
		Allocate(mat._n, mat._m);

		for (int i = 0;i < _n * _m; i++)
			_array[i] = mat._array[i];
	}
	return *this;
}

bool MyMatrix::operator==(const MyMatrix& other) const
{
	if (_n != other._n || _m != other._m)
		return false; 

	for (int i=0;i< _m*_n ; i++)
		if (_array[i] != other._array[i])
			return false;
	return true;
}


MyMatrix::operator double const () const
{
	double sum = 0;
	for (int i = 0;i < _m*_n; i++)
		sum = sum + _array[i];
	return sum;
}

const MyMatrix MyMatrix::operator+(const MyMatrix& mat) const
{
	// 1. Make sure the input in the same size - 
	if (_n != mat._n || _m != mat._m)
		throw "incompatible dimensions of the matrices";

	// 2. allocate output matrix 
	MyMatrix retMat(_n,_m);

	// 3. operation 
	for (int i = 0;i < _m*_n; i++)
		retMat._array[i] = _array[i] + mat._array[i];

	return retMat;
}

const MyMatrix MyMatrix::operator-(const MyMatrix& mat) const
{
	// 1. Make sure the input in the same size - 
	if (_n != mat._n || _m != mat._m)
		throw "incompatible dimensions of the matrices";

	// 2. allocate output matrix 
	MyMatrix retMat(_n, _m);

	// 3. operation 
	for (int i = 0;i < _m*_n; i++)
		retMat._array[i] = _array[i] - mat._array[i];

	return retMat;
}


ostream& operator<<(ostream& os, const MyMatrix& mat)
{
	
	// For each row
	os << "*********************************" << endl;
	for (int i = 0; i < mat._n; i++)
	{
		// For each column 
		for (int j = 0; j < mat._m; j++)
		{
			double d = mat._array[i * mat._m + j]; 
			os << d << " ";
		}
		os << endl;
	}
	os << "*********************************" << endl;
	return os;
}

istream& operator>>(istream& is,MyMatrix& mat)
{
	cout << "enter the matrix dimensions: (rows and then columns)" << endl;
	double rows, columns;
	is >> rows >> columns;
	if (rows <= 0 || columns <= 0)
		throw "invalid values of the matrix dimensions";

	mat.Allocate(rows, columns);

	double input;
	// For each row
	for (int i = 0; i < mat._n; i++)
	{
		// For each column 
		for (int j = 0; j < mat._m; j++)
		{
			cout << "enter the value of the matrix in row number " << i << " and column number " << j << endl;
			is >> input;
			mat._array[i * mat._m + j] = input;
		}
	}
	return is;
}

MyMatrixOp MyMatrix::operator[](int input1)
{
	if (input1 < 0 || input1 > _n - 1)
		throw "out of bounds matrix dimensions";

	return MyMatrixOp(input1,_m,&(_array[0]));
}

const MyMatrix MyMatrix::operator*(double num) const
{
	MyMatrix ret(*this);
	for (int i = 0; i < _n*_m; i++)
		ret._array[i] *= num;
	return ret;
}

const MyMatrix operator*(double num, MyMatrix& mat)
{
	return mat * num;
}

const MyMatrix MyMatrix::operator*(int num) const
{
	MyMatrix ret(*this);
	for (int i = 0; i < _n*_m; i++)
		ret._array[i] *= num;
	return ret;
}

const MyMatrix operator*(int num, MyMatrix& mat)
{
	return mat * num;
}

//A = B * C
const MyMatrix MyMatrix::operator*(const MyMatrix& mat) const
{ 
	// this * mat n*m 
	if (_m != mat._n)
		throw "incompatible dimensions of the matrices multiplication";

	MyMatrix ret(_n, mat._m);

	for (int i = 0; i < ret._n; i++)
	{
		for (int j = 0; j < ret._m; j++)
		{
			//ret._array[i][j] = 0;

			for (int q = 0; q < _m; q++)
			{
				double a = this->_array[i*this->_m + q];
				double b = mat._array[q * mat._m + j];
				ret[i][j] += a * b;
				//ret[i][j] += this->operator[i][q] * mat[q][j];
			}
		}
	}
	return ret;
}


