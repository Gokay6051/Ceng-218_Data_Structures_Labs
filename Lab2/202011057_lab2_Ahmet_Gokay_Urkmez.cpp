// 2 boyutlu vector eklenecek

#include <iostream>

using namespace std;

class SparseMatrix{
private:
	int rows; // number of rows
 	int cols;
 	int Nterms; // number of nonzero elements
 	int capacity; // size of smArray
 	
public:
	//vector<int> smArray;
	
	SparseMatrix(int rows, int cols, int Nterms): rows{rows}, cols{cols}, Nterms{Nterms}, capacity{30} {
		generateRandomSparseMatrix(rows, cols, 1.0*(rows*cols-Nterms)/(rows*cols)*100 ); // Burada Kaldýk
	}  
	
	SparseMatrix generateRandomSparseMatrix(int nrows, int ncols, int ZeroPercentage){
	
	}
	
	friend ostream& operator<<(ostream& OS, SparseMatrix& SM);
	
	
};

ostream& operator<<(ostream& OS, SparseMatrix& SM) {
	/*
    os << t.type << " " << t.make << " " << t.model << " " << t.automanu << " " << "-" << " " << t.price << " " << t.available;
    return os;
	*/
}




int main() {
	/*
	int rows;
 	int cols;
 	int ZeroPercentage;
 	
 	cout << "Please enter number of rows, columns and zero percentage: ";
 	cin >> rows >> cols >> ZeroPercentage;
 	*/
 	int rows, cols, Nterms;
 	cin >> rows >> cols >>  Nterms;
 	int final = 1.0*(rows*cols-Nterms)/(rows*cols)*100;
 	cout << final;
 	
}
