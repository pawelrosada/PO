
#include "stdafx.h"
using namespace std;
#include "matrix.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	string nameA, nameB, nameC, nameD;
	Matrix_vector *matrixA = new Matrix_vector(4, 3, "matrixA.txt");
	Matrix_vector *matrixB = new Matrix_vector(3, 4, "matrixB.txt");
	Matrix_vector *matrixC;
	matrixC = matrixA;
	for (unsigned int i = 0; i < matrixC->get_n(); i++)
		cout << matrixC->return_line(i) << endl;

	matrixC = matrixA->matrix_multiplication(matrixB);
	for (unsigned int i = 0; i < matrixA->get_n(); i++)
		cout << "       " << matrixA->return_line(i) << endl;
	for (unsigned int i = 0; i < matrixB->get_n(); i++)
		cout << matrixB->return_line(i) << "  " << matrixC->return_line(i) << endl;
	nameC = matrixC->save_matrix(matrixC->get_name());
	system("pause");
	return 0;
}

