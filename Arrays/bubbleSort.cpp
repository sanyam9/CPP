#include <iostream>

using namespace std;

int main()
{   int n;
    
    cout<<"Enter number of elements\n";
    cin>>n;
    
	int *arr = new int[n];
    
    cout<<"Enter array:\n";
    for(int i = 0 ; i<n ; i++)
    cin>>arr[i];
    
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    
    for(int i = 0 ; i<n; i++)
    cout<<arr[i]<<" ";
    
    return 0;
}
