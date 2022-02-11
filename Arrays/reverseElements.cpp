#include <iostream>

using namespace std;

int main()
{   int n,i;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"Enter "<<n<<" elements\n";
    int *arr = new int[n];
    
    for(i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    
    for(i = 0 ; i<n/2; i++){
        int t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;
    }
    
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
