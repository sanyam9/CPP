#include <iostream>

using namespace std;

int main()
{   
    int n,i,j;
    cout<<"Enter order of the square matrix\n";
    cin>>n;
    int no = (n*n+n)*0.5;
    int *arr = new int[no];
    cout<<"Enter "<<no<<" elements\n";
    for(i = 0 ; i<no ; i++)
    cin>>arr[i];
    int t = 0;
    for(i = 0 ; i<n ; i++){
        for(j = 0 ; j<n ; j++){
            if(j<=i)
            cout<<arr[t++]<<' ';
            else
            cout<<0<<' ';
        }
        cout<<endl;
    }

    return 0;
}
