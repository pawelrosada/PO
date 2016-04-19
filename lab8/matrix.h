#include <string>
#include <vector>
using namespace std;
class Matrix_vector
{
private:
	vector< vector<double> > matrix;
	int m, n;
public:
	Matrix_vector();
	Matrix_vector(int, int, string);
	void file_read(string);
	void change_matrix(int, int, double);
	string return_cell(int, int);
	string return_line(int);
	string return_column(int);
	string return_all();
	Matrix_vector* add_to_matrix(int);
	void matrix_transpose();
	string get_name();
	string save_matrix(string);
	Matrix_vector* matrix_addition(Matrix_vector *);
	Matrix_vector* matrix_subtraction(Matrix_vector *);
	Matrix_vector* matrix_multiplication(Matrix_vector *);
	int get_n();
	int get_m();
	Matrix_vector* operator + (Matrix_vector &);
	Matrix_vector* operator = (Matrix_vector *);
	Matrix_vector operator+=(Matrix_vector &);
};
