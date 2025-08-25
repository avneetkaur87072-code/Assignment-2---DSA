#include<iostream>
using namespace std;
void diagonal(){
	int n;  // diagonal = n*n
	cout << "Enter the size of diagonal mat : ";
	cin >> n;
	
	int diagonal[n];
	cout << "Enter diagonal elements : ";
	for(int i=0; i<n; i++){
		cin >> diagonal[i];
	}
	
	cout << "Diagonal matrix : "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				cout << diagonal[i] << " ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}	
}


void tridiagonal() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int size = 3 * n - 2;   // number of non-zero elements
    int tri[size];

    cout << "Enter " << size << " elements (lower, main, upper): ";
    for (int i = 0; i < size; i++) {
        cin >> tri[i];
    }

    cout << "Tri-diagonal Matrix : " << endl;

    int k = 0; // index for tri[]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1) {          // lower diagonal
                cout << tri[k] << " ";
                k++;
            }
            else if (i == j) {         // main diagonal
                cout << tri[(n - 1) + i] << " ";
            }
            else if (j - i == 1) {     // upper diagonal
                cout << tri[(n - 1) + n + i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}



void lowerTriangular() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;  // only n(n+1)/2 elements will be non zero
    int lower[size];

    cout << "Enter " << size << " elements (row-wise): ";
    for (int i = 0; i < size; i++) {
        cin >> lower[i];
    }

    cout << "Lower Triangular Matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i * (i + 1)) / 2 + j; 
                cout << lower[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}


void upperTriangular() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;  // only n(n+1)/2 elements needed
    int upper[size];

    cout << "Enter " << size << " elements (row-wise): ";
    for (int i = 0; i < size; i++) {
        cin >> upper[i];
    }

    cout << "Upper Triangular Matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = (i * (2 * n - i + 1)) / 2 + (j - i);
                cout << upper[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}



void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   // only n(n+1)/2 elements
    int sym[size];

    cout << "Enter " << size << " elements (lower triangular row-wise): ";
    for (int i = 0; i < size; i++) {
        cin >> sym[i];
    }

    cout << "Symmetric Matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = (i * (i + 1)) / 2 + j;
                cout << sym[index] << " ";
            } else {
                int index = (j * (j + 1)) / 2 + i; // using symmetry
                cout << sym[index] << " ";
            }
        }
        cout << endl;
    }
}



int main(){
	diagonal();
	tridiagonal();
	lowerTriangular();
    upperTriangular();	
    symmetricMatrix();  
	return 0;
}
