#include "stdafx.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

Matrix_vector::Matrix_vector(int _n, int _m, string name)
{
	n = _n;
	m = _m;
	for (int i = 0; i < n; i++)
	{
		vector < double > tmp;
		for (int j = 0; j < m; j++)
			tmp.push_back(0.0);
		matrix.push_back(tmp);
	}
	file_read(name);
}
void Matrix_vector::file_read(string name)
{
	ifstream file(name);
	if (!file.is_open())
		throw exception("Can't open file");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			file >> matrix[i][j];
			if (file.eof()) break;
		}
		if (file.eof()) break;
	}
}
void Matrix_vector::change_matrix(int a, int b, double new_matrix)
{
	matrix[a][b] = new_matrix;
}
string Matrix_vector::return_cell(int a, int b)
{
	ostringstream strs;
	strs << matrix[a][b];
	return strs.str();
}
string Matrix_vector::return_line(int a)
{
	ostringstream strs;
	for (int i = 0; i < m; i++)
		strs << matrix[a][i] << " ";
	return strs.str();
}
string Matrix_vector::return_column(int a)
{
	ostringstream strs;
	for (int i = 0; i < n; i++)
		strs << matrix[i][a] << "\n";
	return strs.str();
}
string Matrix_vector::return_all()
{
	ostringstream strs;
	for (int i = 0; i < n; i++)
		strs << return_line(i) << "\n";
	return strs.str();
}
Matrix_vector* Matrix_vector::add_to_matrix(int a)
{
	Matrix_vector *tmp = new Matrix_vector;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp->matrix[i][j] = matrix[i][j] + a;
	return tmp;
}
void Matrix_vector::matrix_transpose()
{
	if (n == m)
	{
		double pom;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < m; j++)
			{
			pom = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = pom;
			}
	}
	else
	{
		vector< vector<double> > matrix_tmp;
		for (int i = 0; i < m; i++)
		{
			vector <double> tmp;
			for (int j = 0; j < n; j++)
				tmp.push_back(0.0);
			matrix_tmp.push_back(tmp);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				swap(matrix_tmp[j][i], matrix[i][j]);
		matrix = matrix_tmp;
		int pom = n;
		n = m;
		m = pom;
	}
}
string Matrix_vector::get_name()
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	ostringstream ss;
	char a = (rand() % 20) + 65;
	char b = (rand() % 20) + 65;
	ss << a << b << now.tm_hour << now.tm_min << now.tm_sec << ".txt";
	return ss.str();
}
string Matrix_vector::save_matrix(string name)
{
	ofstream file(name);
	if (!file.is_open())
		throw exception("Can't open file");
	file << return_all();
	return name;
}
Matrix_vector* Matrix_vector::matrix_addition(Matrix_vector *name)
{
	Matrix_vector *tmp = new Matrix_vector;
	if (n != name->n && m != name->m)
		throw exception("Can't add these matrices");
	else
	{
		for (unsigned int i = 0; i < n; i++)
			for (unsigned int j = 0; j < m; j++)
			{
			tmp->matrix[i][j] = matrix[i][j] + name->matrix[i][j];
			}
	}
	return tmp;
}
Matrix_vector* Matrix_vector::matrix_subtraction(Matrix_vector *name)
{
	Matrix_vector *tmp = new Matrix_vector;
	if (n != name->n && m != name->m)
		throw exception("Can't deduct these matrices");
	else
	{
		for (unsigned int i = 0; i < n; i++)
			for (unsigned int j = 0; j < m; j++)
			{
			tmp->matrix[i][j] = matrix[i][j] - name->matrix[i][j];
			}
	}
	return tmp;
}
Matrix_vector* Matrix_vector::matrix_multiplication(Matrix_vector *name)
{
	Matrix_vector *tmp = new Matrix_vector;
	int pom;
	if (n != m)
		throw exception("Can't multiply these matrices");
	else
	{
		for (unsigned int i = 0; i < n; i++)
			for (unsigned int j = 0; j < m; j++)
			{
			pom = 0;
			for (unsigned int k = 0; k < m; k++)
				pom = (pom + matrix[i][k] * name->matrix[k][j]);
			tmp->matrix[i][j] = pom;
			}
	}
	return tmp;
}
int Matrix_vector::get_m()
{
	return m;
}
int Matrix_vector::get_n()
{
	return n;
}
Matrix_vector* Matrix_vector::operator + (Matrix_vector &name )
{
	Matrix_vector *tmp = new Matrix_vector;
	if (n != name.n && m != name.m)
		throw exception("Can't deduct these matrices");
	else
	{
		for (unsigned int i = 0; i < this->n; i++)
			for (unsigned int j = 0; j < this->m; j++)
				tmp->matrix[i][j] = this->matrix[i][j] + name.matrix[i][j];
	}
	return tmp;
}
Matrix_vector* Matrix_vector::operator=(Matrix_vector *name)
{
	//copy(name->matrix, tmp->matrix);
	this->matrix = name->matrix;
	return name;
}