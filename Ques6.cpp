#include <iostream>
using namespace std;

void convertToSparse(int mat[10][10], int m, int n, int sparse[100][3]) {
    int k = 1; // start filling from row 1 (row 0 stores mat data)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    // store rows, cols, non-zero count at sparse[0]
    sparse[0][0] = m;
    sparse[0][1] = n;
    sparse[0][2] = k - 1;
}




void displaySparse(int sparse[100][3]) {
    for (int i = 0; i <= sparse[0][2]; i++) {
        cout << sparse[i][0] << "   "<< sparse[i][1] << "   " << sparse[i][2] << endl;
    }
}




void transposeSparse(int A[100][3], int B[100][3]){
	B[0][0] = A[0][1]; // rows of B = cols of A
    B[0][1] = A[0][0]; // cols of B = rows of A
    B[0][2] = A[0][2]; // same number of non-zeros
    
    int k=1;
    for(int col = 0; col < A[0][1]; col++){
    	for(int i=1; i<=A[0][2]; i++){
    		if(A[i][1] == col){
    			B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
			}
		}
	}
}



int main() {
    int m, n;
    cout << "Enter rows and cols: ";
    cin >> m >> n;

    int A[10][10];
    cout << "Enter the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int sparse[100][3];
    convertToSparse(A, m, n, sparse);

    cout << "Sparse Matrix : " << endl;
    displaySparse(sparse);
    
    cout << endl;
    
    int B[100][3];
    transposeSparse(sparse, B);
    
    cout << "Transpose of Sparse matrix is: " << endl;
    displaySparse(B);
    
    cout << endl;
    
    return 0;
}


