#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

class SparseMatrix{
private:
	int rows; // number of rows
 	int cols;
 	int Nterms; // number of nonzero elements
 	int capacity; // size of smArray
 	//float ZeroPercentage;
 	int **sparse;
 	
public:
	SparseMatrix(int rows, int cols, int Nterms): rows{rows}, cols{cols}, Nterms{Nterms}, capacity{30} {
		formSparse();
		generateRandomSparseMatrix(); // Burada Kaldýk
	}  
	
	void generateRandomSparseMatrix(){
		srand(time(NULL));
		float ZeroPer =  calculateZeroPer();
		int random;
		
		Nterms = 0;
		
		for(int i=0; i<rows; ++i) {
			for(int j=0; j<cols; ++j) {
				random = rand() % 100;
				
				if(random*1.0 > ZeroPer) {
					sparse[i][j] = rand() % 9 + 1; 
					++Nterms;
				}			
				else
					sparse[i][j] = 0;
			}
		}
	}
	
	void transpose() {
		int tempint;
		
		int **temp;
		temp = new int*[cols];
		
		for(int i=0; i<cols; ++i) {
			temp[i] = new int[rows];
		}
			
		for(int i=0; i<rows; ++i) {
			for(int j=0; j<cols; ++j) {
					temp[j][i] = sparse[i][j];
			}
		}
		
		tempint = cols;
		cols = rows;
		rows = tempint;
		
		copy(temp);
		delete [] temp;
	}
	
	void formSparse() {
		sparse = new int*[rows];
		
		for(int i=0; i<rows; ++i) {
			sparse[i] = new int[cols];
		}
	}
	
	float calculateZeroPer() {
		return 1.0*(rows*cols-Nterms)/(rows*cols)*100;
	}
	
	void copy(int **temp) {
		formSparse();
		
		for(int i=0; i<rows; ++i) {
			for(int j=0; j<cols; ++j) {
					sparse[i][j] = temp[i][j];
			}
		}
	}
	
	void Sparse() {
		int tempint;
		int k = 0;
		
		int **temp;
		temp = new int*[3];
		
		for(int i=0; i<3; ++i) {
			temp[i] = new int[Nterms];
		}
			
		for(int i=0; i<rows; ++i) {
			for(int j=0; j<cols; ++j) {
				if(sparse[i][j] != 0) {
					temp[0][k] = i+1;
					temp[1][k] = j+1;
					temp[2][k] = sparse[i][j];
					++k;
				}
			}
		}
		
		rows = 3;
		cols= Nterms;
		
		copy(temp);
		delete [] temp;
	}
	
	~SparseMatrix() {
		delete [] sparse;
	}
	
	friend ostream& operator<<(ostream& OS, SparseMatrix& SM);
};

ostream& operator<<(ostream& OS, SparseMatrix& SM) {
	for(int i=0; i<SM.rows; ++i) {
			for(int j=0; j<SM.cols; ++j) {
					cout << SM.sparse[i][j] << " ";
			}
			cout << endl;
	}
	
	return OS;
}


int main() {
 	int rows, cols, Nterms;
 	int **arr1 = new int*[5];
 	arr1[0] = new int[5];
 	cout <<"Enter number of rows, columns and nonzero elements: ";
 	cin >> rows >> cols >>  Nterms;
 	
 	SparseMatrix s1(rows, cols, Nterms);

 	cout << "Original Matrix:" << endl << s1 << endl;
 	
 	s1.transpose();
 	cout << "Transposed Matrix:" << endl << s1 << endl;
 	
 	s1.Sparse();
 	cout << "Sparse Matrix:" << endl << s1;
}
