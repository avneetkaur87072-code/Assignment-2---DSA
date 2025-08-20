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

    int k = 0; // index for tri array
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


int main(){
	diagonal();
	tridiagonal();
	return 0;
}


