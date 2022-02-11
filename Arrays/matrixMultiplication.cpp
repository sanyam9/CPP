#include <iostream>

using namespace std;

int main()
{   int i,j,k,m1,n1,m2,n2;
    cout<<"Enter rows,columns for 1st matrix\n";
    cin>>m1>>n1;
    cout<<"Enter rows,columns for 2nd matrix\n";
    cin>>m2>>n2;
    int a[m1][n1];
    int b[m2][n2];
    
    if(n1 != m2){
        cout<<"Matrix multiplication is not possible!\n";
        return 0;
    }
    cout<<"Matrix 1:\n";
    for(i=0;i<m1;i++){
        cout<<"Enter "<<n1<<" elements for row "<<i+1<<endl;
        for(j=0;j<n1;j++)
            cin>>a[i][j];
    }
    
    cout<<"Matrix 2:\n";
    for(i=0;i<m2;i++){
        cout<<"Enter "<<n2<<" elements for row "<<i+1<<endl;
        for(j=0;j<n2;j++)
            cin>>b[i][j];
    }
    
    int c[m1][n2]={};
    
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            for(k=0;k<n1;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    cout<<"ANSWER:\n";
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
}

