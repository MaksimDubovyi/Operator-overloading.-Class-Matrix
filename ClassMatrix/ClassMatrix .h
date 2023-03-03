#pragma once
using namespace std;
void RussianMessage(const char* s);
class matrix
{
	int** p;
	int row, col;
public:
	matrix(); // конструктор по умолчанию
	matrix(int, int); // конструктор с параметрами
	matrix(const matrix&); // конструктор копирования
	matrix(matrix&&); // конструктор переноса
	~matrix(); // деструктор
	matrix& operator = (const matrix&); // перегруженный оператор
	//// присваивания с копированием
	matrix& operator = (matrix&&); // перегруженный оператор
	//// присваивания с переносом
	
	//// увеличение на 1 каждого элемента матрицы
	matrix& operator ++(); // префиксный инкремент
	matrix operator ++(int); // постфиксный инкремент
	/// уменьшение на 1 каждого элемента матрицы
	matrix& operator --(); // префиксный декремент
	matrix operator --(int); // постфиксный декремент
	matrix operator+(const matrix&) const; // сложение матриц
	matrix operator*(const matrix&) const; // умножение матриц
	int& operator()(int, int); // установка / получение значения
	//// элемента матрицы
	friend ostream& operator << (ostream&, matrix&);
	// печать матрицы
	friend istream& operator >> (istream&, matrix&);
	// ввод данных в матрицу
	matrix&  operator += (const matrix& p1);
};