#include <iostream>
#include <vector>

using namespace std;

class Matrix{
private:
	int rows;
	int cols;
	vector<vector<int> > data;
	
public:
	Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, vector<int> (cols,0)){}
	
	int &operator()(int i, int j) {
		return data[i][j];
	}
	
	int operator()(int i, int j) const{
		return data[i][j];
	}
	
	Matrix operator +(const Matrix& other) {
		Matrix result(this->rows, this->cols);
		// function will be add to matrices have different dimensions
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
		
		return result;
	}
	
	friend ostream& operator<<(ostream &os, Matrix& matrix);
};

ostream& operator<<(ostream &os, Matrix& matrix){
	for(int i=0; i<matrix.rows; ++i) {
		for(int j=0; j<matrix.cols; ++j){
			cout << matrix.data[i][j] << " ";		
		}
		cout << endl;
	}
	return os;
}


int main() {	
	Matrix a(2, 3);
    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;
    a(1, 0) = 4;
    a(1, 1) = 5;
    a(1, 2) = 6;

    Matrix b(2, 3);
    b(0, 0) = 1;
    b(0, 1) = 2;
    b(0, 2) = 3;
    b(1, 0) = 4;
    b(1, 2) = 5;
    b(1, 3) = 6;

	cout << "a:\n" << a << '\n';
    cout << "b:\n" << b << '\n';
	
	Matrix c = a + b;
    cout << "c = a + b:\n" << c << endl;
	
}

//Parentheses Matching araþtýr
