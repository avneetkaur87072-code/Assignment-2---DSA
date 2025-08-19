#include <iostream>
using namespace std;

void convertToSparse(int mat[10][10], int m, int n, int sparse[100][3]) {
    int k = 1; // start filling from row 1 (row 0 stores metadata)
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




void addSparse(int a[100][3], int b[100][3], int c[100][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible! Dimensions differ.\n";
        c[0][2] = 0;
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] ||
           (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] ||
                (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
        else { // same position
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    // Copy remaining
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][2] = k - 1; // number of non-zeros
}



void multiplySparse(int a[100][3], int b[100][3], int d[100][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible! Dimensions mismatch.\n";
        d[0][2] = 0;
        return;
    }

    int bt[100][3];
    transposeSparse(b, bt);

    d[0][0] = a[0][0];
    d[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= bt[0][2]; j++) {
            if (a[i][1] == bt[j][1]) {
                int r = a[i][0];
                int col = bt[j][0];
                int v = a[i][2] * bt[j][2];

                // Check if (r, col) already exists
                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (d[x][0] == r && d[x][1] == col) {
                        d[x][2] += v;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    d[k][0] = r;
                    d[k][1] = col;
                    d[k][2] = v;
                    k++;
                }
            }
        }
    }
    d[0][2] = k - 1;
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
    
    int C[100][3];
    addSparse(sparse,B,C);
    
    cout << "The addition of the two sparse matrix : "<< endl;
    displaySparse(C);
    
    cout << endl;
    
    int D[100][3];
    multiplySparse(sparse,B,D);
    
    cout << "Multiply of two matrices is : "<<endl;
    displaySparse(D);
    
    return 0;
}

