#include <iostream>

using namespace std;

int main()
{   int m,n,i,j;
    cout<<"Enter rows,columns for the matrix\n";
    cin>>m>>n;
    int a[m][n];
    for(i=0;i<m;i++){
        cout<<"Enter "<<n<<" elements for row "<<i+1<<endl;
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    int sumRow[m] = {};
    int sumColumn[n] = {};
    
    for(i = 0 ; i<m ; i++){
        for(j = 0 ; j<n ; j++)
        sumRow[i] += a[i][j];
    }
    
    for(j = 0 ; j<n ; j++){
        for(i = 0 ; i<m ; i++)
        sumColumn[j] += a[i][j];
    }

    for(i=0;i<m;i++)
    cout<<"Sum of row "<<i+1<<' '<<sumRow[i]<<endl;
    
    for(i=0;i<n;i++)
    cout<<"Sum of column "<<i+1<<' '<<sumColumn[i]<<endl;
    
    return 0;
}

