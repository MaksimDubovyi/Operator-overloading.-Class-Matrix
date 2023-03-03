#include <iostream>
#include <windows.h>
#include "ClassMatrix .h"
using namespace std;

int main()
{
	matrix a(2,5 ),b(5,4),x;
	matrix a1(2,5);
	cout << a << endl;
 	cout << b << endl;
	x = a * b;
	cout << x << endl;
	x = a + a1;
	cout << a << endl;
	cout << a1 << endl;

	cout << x << endl;
	
	b = a;
	--a++;

	cout << a<<endl;
	cout << b << endl;
	b = a++;
	cout << b << endl;
	b = b--;
	cout << b << endl;
	x = a * b;
	matrix b1(5, 5);
	x = a +b1;
	matrix a3(2, 5), b3(2, 5), x1;
	cout << a3 << endl;
	cout << b3 << endl;
	a3 += b3;
	cout << a3 << endl;
}


