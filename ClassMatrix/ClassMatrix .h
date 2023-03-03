#pragma once
using namespace std;
void RussianMessage(const char* s);
class matrix
{
	int** p;
	int row, col;
public:
	matrix(); // ����������� �� ���������
	matrix(int, int); // ����������� � �����������
	matrix(const matrix&); // ����������� �����������
	matrix(matrix&&); // ����������� ��������
	~matrix(); // ����������
	matrix& operator = (const matrix&); // ������������� ��������
	//// ������������ � ������������
	matrix& operator = (matrix&&); // ������������� ��������
	//// ������������ � ���������
	
	//// ���������� �� 1 ������� �������� �������
	matrix& operator ++(); // ���������� ���������
	matrix operator ++(int); // ����������� ���������
	/// ���������� �� 1 ������� �������� �������
	matrix& operator --(); // ���������� ���������
	matrix operator --(int); // ����������� ���������
	matrix operator+(const matrix&) const; // �������� ������
	matrix operator*(const matrix&) const; // ��������� ������
	int& operator()(int, int); // ��������� / ��������� ��������
	//// �������� �������
	friend ostream& operator << (ostream&, matrix&);
	// ������ �������
	friend istream& operator >> (istream&, matrix&);
	// ���� ������ � �������
	matrix&  operator += (const matrix& p1);
};