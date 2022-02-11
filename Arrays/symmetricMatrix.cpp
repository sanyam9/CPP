#include<iostream>
using namespace std;

int main() {
    int i,j, m, t=0, k=0;
	cout<<"Enter the number of rows in Matrix:\n";
	cin>> m;
    int size = m*(m+1)/2;
    int a[size];
    cout<<"Enter the matrix\n";
    for(i = 0; i < size; i++)
        cin>>a[i];
    cout<<"\nThe symmetric matrix is...\n";
    for(i = 0; i < m; i++) { 
        for(j = 0; j <m; j++) {   
            if(i<=j)  {
                cout<<a[t]<<" ";
				t++;  }
            else      {
                k = i + j*m - j*(j+1)/2;
				cout<<a[k]<<" ";
            } }
        cout<<"\n"; }
return 0; 
}
