#include <iostream>
#include <windows.h>
#include "ClassMatrix .h"
using namespace std;
void RussianMessage(const char* s)
{
	char* buf = new char[strlen(s) + 1];
	CharToOemA(s, buf);
	cout << buf;
	delete[] buf;
}
//Дефолтный конструктор
matrix::matrix()
{
	RussianMessage("\n Дефолтный конструктор\n"); cout << this<<endl;
	p=nullptr;
    row=0, col=0;
}
// конструктор с параметрами
matrix::matrix(int row1, int col1)
{
	RussianMessage("\n конструктор с параметрами\n"); cout << this << endl;
	row = row1;
	col = col1;
	p = new int* [row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
		
	}
	for (int i = 0; i < row; i++)
		{
		    for(int j = 0; j < col; j++)
			{
				p[i][j] = rand() % 50;
			}
		}
	
}
// конструктор копирования
matrix::matrix(const matrix&p1)
{
	RussianMessage("\n конструктор копирования\n"); cout << this << endl;
	row = p1.row;
	col = p1.col;
	p = new int* [row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = p1.p[i][j];
		}
	}
}
// конструктор переноса
matrix::matrix(matrix&&p1)
{
	RussianMessage("\nКонструктор переноса \n"); cout << this << endl;
	p = p1.p;
	row = p1.row;
	col = p1.col;
	p1.p = nullptr;
	p1.row = 0;
	p1.col = 0;

}
// деструктор
matrix::~matrix()
{
	RussianMessage("\n Деструктор\n"); cout << this << endl;
	for (int i = 0; i < row; i++)
		delete[] p[i];
	delete[] p;
}

matrix& matrix::operator=(const matrix&p1)
{
	RussianMessage("\n Перегруженный оператор присваивания с копированием \n");
	if (this == &p1)
		return *this;
	delete[] this->p;
	row = p1.row;
	col = p1.col;
	p = new int*[row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = p1.p[i][j];
		}
	}
}

matrix& matrix::operator=(matrix&&p1)
{
	RussianMessage("\n Перегруженный оператор присваивания с переносом \n");
	if (this == &p1)
		return *this;
	delete[]p;
	row = p1.row;
	col = p1.col;
	p1.row = 0;
	p1.col = 0;
	p = p1.p;
	p1.p = nullptr;
	return *this;
}

matrix& matrix::operator++()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			 p[i][j]++;
		}
	}
	return *this;
}

matrix matrix::operator++(int)
{
	matrix a = *this;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a(i,j)++;
		}
	}
	return a;
}

matrix& matrix::operator--()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j]--;
		}
	}
	return *this;
}

matrix matrix::operator--(int)
{
	matrix a = *this;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a(i, j)--;
		}
	}

	return a;
}

matrix matrix::operator+(const matrix&p1) const
{
	matrix a(row,col);
	if (row == p1.row && col == p1.col)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				a(i, j)=p[i][j]+p1.p[i][j];
	}
	else
	{
		RussianMessage("\n Некорректный ввод! \n");
		return *this;
	}
	return a;
}

matrix matrix::operator*(const matrix&p1) const
{
	matrix a1(row, p1.col);
	int c=0,a,b;
	if (col == p1.row)
	{
		for (int d = 0; d < row; d++)
		{
			for (int i = 0; i < p1.col; i++)
			{
				for (int j = 0; j < col; j++)
				{
					a = p[d][j];
					b = p1.p[j][i];
					c = c + a * b;

				}
				a1(d,i)=c ;
				c = 0;
			}
		}
	}
	else
	{
		RussianMessage("\n Некорректный ввод! \n");
		return *this;


	}

	return  a1;
}

int& matrix::operator()(int row1, int col1)
{
	return p[row1][col1];
}

matrix& matrix::operator+=(const matrix& p1)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = p[i][j] + p1.p[i][j];
		}
	}

return *this;
}

ostream& operator<<(ostream& cout, matrix& p1)
{
	for (int i = 0; i < p1.row; i++)
	{
		for (int j = 0; j < p1.col; j++)
		{
			cout << " " << p1(i, j);
		}
		cout << endl;
	}
	return cout;
}

istream& operator>>(istream&cin, matrix&p1)
{
	for (int i = 0; i < p1.row; i++)
	{
		for (int j = 0; j < p1.col; j++)
		{

			cin >> p1(i, j);

		}
	}

	return cin;

}
