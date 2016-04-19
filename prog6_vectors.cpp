
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
	vector< vector<double> > matrix;
	int m, n;
public:

	Matrix(int _n, int _m, string name)
	{
		n = _n;
		m = _m;
		for (int i = 0; i < n; i++)
		{
			vector<double> vec;
			for (int j = 0; j < m; j++)
				vec.push_back(0.0);

			matrix.push_back(vec);
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
				vector <double> vec;
				for (int j = 0; j < n; j++)
					vec.push_back(0.0);
				matrix_tmp.push_back(vec);
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					matrix_tmp[j][i] = matrix[i][j];
			matrix=matrix_tmp;
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
		ss << a << now.tm_hour << now.tm_min << now.tm_sec << ".txt";
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
	srand(static_cast<unsigned int>(time(NULL)));
	Matrix matrix1(4, 3, "matrix.txt");
	matrix1.change_matrix(1, 1, 10);
	matrix1.change_matrix(2, 0, 15);
	matrix1.change_matrix(3, 1, 3);
	matrix1.change_matrix(2, 1, 8);
	matrix1.change_matrix(1, 2, 13);
	string name1, name2, name3;
	name1 = matrix1.save_matrix(matrix1.getTime());

	Matrix matrix2(4, 3, name1);
	matrix2.matrix_transpose();
	name2 = matrix2.save_matrix(matrix1.getTime());

	Matrix matrix3(3, 4, name2);
	matrix3.add_to_matrix(5);
	name3 = matrix3.save_matrix(matrix1.getTime());

	
	return 0;
}

