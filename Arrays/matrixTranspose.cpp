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
    for(int i = 0 ; i<m; i++){
        for(int j = 0 ; j<n; j++){
            cout<<a[i][j]<<' ';}
            cout<<endl;}
            
    cout<<"TRANSPOSE:"<<endl;        
    
    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j<m; j++){
            cout<<a[j][i]<<' ';}
            cout<<endl;}        
    return 0;
}

