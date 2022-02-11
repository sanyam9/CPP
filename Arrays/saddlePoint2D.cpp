/* Saddle Point
Example:
Input: 
		[4 , 5 , 6]
		[7 , 8 , 9]
		[5 , 1 , 3]
Output: 7		
*/
#include <iostream>

using namespace std;

int main()
{   int i,j,k,m,n;
    cout<<"Enter number of rows and columns:\n";
    cin>>m>>n;
    int arr[m][n];
    for(i=0;i<m;i++){
        cout<<n<<" elements for Row "<<i+1<<endl;
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    }
    cout<<"Array: -\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
    }
   int min;
   
   for(i = 0 ; i<m ; i++){
       min = 0;
       for(j=0;j<n;j++){
           if(arr[i][j]<arr[i][min])
           min = j;
       }
       for(int k = 0 ; k<m ; k++){
           if(arr[k][min]>arr[i][min])
           min = -1;
           }       
        if (min!=-1)
        cout<<arr[i][min]<<" at ("<<i<<","<<min<<")"<<endl;
   }
    return 0;
}
