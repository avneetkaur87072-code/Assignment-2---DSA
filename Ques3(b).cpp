#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {1,2,3,4,6,7,8,9,10};
    
    int n=9;
    int m=10;
    int st=0; 
    int end = n-1;
    int mid;
    int missing = -1;
    
    while(st<=end){
        mid = st+(end-st)/2;
        if (arr[mid] == mid + 1) {
            st = mid + 1;
        } 
        
        else {
            missing = mid + 1;  
            end = mid - 1;
        }
    }
    cout << missing  << endl;
   
    return 0;
}
