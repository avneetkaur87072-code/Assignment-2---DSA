#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    
    int n=9;
    int m=n+1;
    
    int actualSum = m*(m+1)/2;
    cout << actualSum << endl;
    
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    cout << sum << endl;
    
    cout << "missing number : "<< actualSum - sum << endl;

    return 0;
}
