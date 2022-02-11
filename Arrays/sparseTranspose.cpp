/*Transpose of Sparse Matrix
Input - R C V
		0 2 1
		0 3 2
		1 0 1
		2 3 3
Output- R C V 
		0 1 0
		2 0 1
		3 0 2
		3 2 3
*/
#include <iostream>

using namespace std;

int main()
{   int m;
    cout<<"Enter the number of non-zero elements\n";
    cin>>m;
	int arr[m][3];
	cout<<"Enter the triplet:\n";
    cout<<"R "<<"C "<<"V\n"; 
    for(int i = 0 ; i<m ; i++)
    cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    
    cout<<"Transpose: \n";
    cout<<"R "<<"C "<<"V\n"; 
    
    int cmax = 0;
    for(int i = 1 ; i<m ; i++){
        if(arr[cmax][1]<arr[i][1])
        cmax=i;
    }
    for(int i = 0 ; i<=arr[cmax][1] ; i++){
        for(int j = 0 ; j<m ; j++){
            if(i == arr[j][1])
            cout<<arr[j][1]<<" "<<arr[j][0]<<" "<<arr[j][2]<<endl;
        }
    }
    return 0;
}
