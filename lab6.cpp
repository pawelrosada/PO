#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Matrix
{
private:
	double **matrix;
	int m, n;
public:

	Matrix(int _n, int _m, string name)
	{
		n = _n;
		m = _m;
		matrix = new double*[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new double[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] = 0;
		file_read(name);
	}
	void file_read(string name)
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
	void free_matrix()
	{
		for (int i = 0; i < n; i++)
			delete matrix[i];
		delete matrix;
	}
	void change_matrix(int a, int b, double new_matrix)
	{
		matrix[a][b] = new_matrix;
	}
	string return_cell(int a, int b)
	{
		ostringstream strs;
		strs << matrix[a][b];
		return strs.str();
	}
	string return_line(int a)
	{
		ostringstream strs;
		for (int i = 0; i < m; i++)
			strs << matrix[a][i] << " ";
		return strs.str();
	}
	string return_column(int a)
	{
		ostringstream strs;
		for (int i = 0; i < n; i++)
			strs << matrix[i][a] << "\n";
		return strs.str();
	}
	string return_all()
	{
		ostringstream strs;
		for (int i = 0; i < n; i++)
			strs << return_line(i) << "\n";
		return strs.str();
	}
	void add_to_matrix(int a)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] += a;
	}
	void matrix_transpose()
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
			double **matrix_tmp = new double*[m];
			for (int i = 0; i < m; i++)
				matrix_tmp[i] = new double[n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					matrix_tmp[j][i] = matrix[i][j];
			matrix = matrix_tmp;
			int pom = n;
			n = m;
			m = pom;
		}
	}
	string getTime()
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
	string save_matrix(string name)
	{
		ofstream file(name);
		if (!file.is_open())
			throw exception("Can't open file");
		file << return_all();
		return name;
	}
};
class Matrix_vector
{
private:
	vector< vector<double> > matrix;
	int m, n;
public:

	Matrix_vector(int _n, int _m, string name)
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
	void file_read(string name)
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
	void change_matrix(int a, int b, double new_matrix)
	{
		matrix[a][b] = new_matrix;
	}
	string return_cell(int a, int b)
	{
		ostringstream strs;
		strs << matrix[a][b];
		return strs.str();
	}
	string return_line(int a)
	{
		ostringstream strs;
		for (int i = 0; i < m; i++)
			strs << matrix[a][i] << " ";
		return strs.str();
	}
	string return_column(int a)
	{
		ostringstream strs;
		for (int i = 0; i < n; i++)
			strs << matrix[i][a] << "\n";
		return strs.str();
	}
	string return_all()
	{
		ostringstream strs;
		for (int i = 0; i < n; i++)
			strs << return_line(i) << "\n";
		return strs.str();
	}
	void add_to_matrix(int a)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] += a;
	}
	void matrix_transpose()
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
	string getTime()
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
	string save_matrix(string name)
	{
		ofstream file(name);
		if (!file.is_open())
			throw exception("Can't open file");
		file << return_all();
		return name;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int x = 1000000;
	///Czas dzialania na tablicach: 2.523
	//Czas dzialania na vectorach: 2.13

	//Czas dzialania na tablicach: 2.183
	//Czas dzialania na vectorach: 2.102

	srand(static_cast<unsigned int>(time(NULL)));
	//tablice
	clock_t begin, end;
	double time_spent;

	Matrix matrix1(30, 30, "matrix.txt");
	matrix1.change_matrix(1, 1, 10);
	matrix1.change_matrix(2, 0, 15);
	matrix1.change_matrix(3, 1, 3);
	matrix1.change_matrix(2, 1, 8);
	matrix1.change_matrix(1, 2, 13);
	string name1, name2, name3;
	name1 = matrix1.save_matrix(matrix1.getTime());

	Matrix matrix2(30, 30, name1);

	begin = clock();
	for (unsigned int i = 0; i<x; i++)
		matrix2.matrix_transpose();
	end = clock();

	name2 = matrix2.save_matrix(matrix2.getTime());

	Matrix matrix3(30, 30, name2);
	matrix3.add_to_matrix(5);
	name3 = matrix3.save_matrix(matrix3.getTime());

	matrix3.free_matrix();
	matrix2.free_matrix();
	matrix1.free_matrix();


	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Czas dzialania na tablicach: " << time_spent << endl;

	//vectory


	Matrix_vector matrix_vector1(30, 30, "matrix.txt");
	matrix_vector1.change_matrix(1, 1, 10);
	matrix_vector1.change_matrix(2, 0, 15);
	matrix_vector1.change_matrix(3, 1, 3);
	matrix_vector1.change_matrix(2, 1, 8);
	matrix_vector1.change_matrix(1, 2, 13);
	string name_vector1, name_vector2, name_vector3;
	name_vector1 = matrix_vector1.save_matrix(matrix_vector1.getTime());

	Matrix_vector matrix_vector2(30, 30, name1);

	begin = clock();
	for (unsigned int i = 0; i<x; i++)
		matrix_vector2.matrix_transpose();
	end = clock();

	name_vector2 = matrix_vector2.save_matrix(matrix_vector2.getTime());

	Matrix_vector matrix_vector3(30, 30, name2);
	matrix_vector3.add_to_matrix(5);
	name_vector3 = matrix_vector3.save_matrix(matrix_vector3.getTime());


	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Czas dzialania na vectorach: " << time_spent << endl;
	system("pause");
	return 0;
}

