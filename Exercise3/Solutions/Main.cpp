#include "MyMatrix.h"
#include "MyMatrixOp.h"

//const MyMatrix operator
using namespace std;

int main()
{
	{
		MyMatrix a;
		try
		{
			cin >> a;
		}
		catch (char * str)
		{
			cout << str << endl;
		}
		cout << a;
		MyMatrix b(2, 2);
		b[0][0] = 1;
		b[0][1] = 2;
		b[1][0] = 3;
		b[1][1] = 4;
		MyMatrix c(2, 2);
		c[0][0] = 2;
		c[0][1] = 2;
		c[1][0] = 2;
		c[1][1] = 2;
		cout << b;
		cout << c;
		MyMatrix d;
		try
		{
			d = a + b + c;
		}
		catch (char * str)
		{
			cout << str << endl;
		}
		cout << d;
	}

	{
		MyMatrix a(2, 3);
		MyMatrix b(3, 2);

		a[0][0] = 1;
		a[0][1] = 2;
		a[0][2] = 3;

		a[1][0] = 4;
		a[1][1] = 5;
		a[1][2] = 6;

		cout << a;

		b[0][0] = 7;
		b[0][1] = 8;
		b[1][0] = 9;
		b[1][1] = 10;
		b[2][0] = 11;
		b[2][1] = 12;

		cout << b;

		b = b * 3;
		cout << b;
		b = 3 * b;
		cout << b;

		MyMatrix c = a.operator*(b);

		cout << c;
	}

	{
		MyMatrix a(100, 99);
		MyMatrix b(100, 100);
		bool isequal = a == b;
		cout << isequal << endl;
		a = b;
		isequal = a == b;
		cout << isequal << endl;
	}

	{
		MyMatrix a;
		a[0][0] = 1; 
		a[0][1] = 2;
		a[0][2] = 5;
		a[1][0] = 7;
		a[1][1] = 4;
		a[1][2] = 3;
		a[2][0] = 9;
		a[2][1] = 5;
		a[2][2] = 8;

		cout << a;
		
		MyMatrix b(a);

		cout << b;

		MyMatrix c(b);

		MyMatrix d = (a + b) - c;

		double sum = (double)a;
		cout << sum << endl; 
	}




	system("pause");
	return 0;
}