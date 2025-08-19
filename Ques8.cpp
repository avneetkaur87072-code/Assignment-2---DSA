#include<iostream>
using namespace std;
//Write a program to count the total number of distinct elements in an array of length n.
int main(){
	int n;
	cout << "Enter the size of array : ";
	cin >> n;
	
	int arr[n];
	cout << "Enter the array elements : ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	int count = 0; // distinct elements count
	
	for(int i=0; i<n; i++){
		bool isduplicate = false;
		for(int j=0; j<i; j++){
			if(arr[i] == arr[j]){
				isduplicate = true;
				break;
			}	
		}
		if(!isduplicate){
			count ++;
		}
	}
	
	cout << "Distinct elements are : "<< count << endl;
	return 0;
}
