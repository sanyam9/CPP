// Missing Number (Consecutive)
// Example:-
// Input -> [21,21,22,25,28]
// Output -> 23 24 26 27

#include <iostream>

using namespace std;

int main()
{
    int arr[100],n;
    cout<<"Enter number of elements\n";
    cin>>n;
    
    cout<<"Enter array: \n";
    for(int i = 0 ; i<n ; i++)
    cin>>arr[i];
    
    for(int i = arr[0]+1 ; i<arr[n-1] ; i++){
    	int chk = 1;
		for(int j = 1 ; j<n-1;j++){
		if(i == arr[j]){
		chk =0;
		break;}
	}
	if(chk)
	cout<<i<<" ";
	}
    return 0;
}
