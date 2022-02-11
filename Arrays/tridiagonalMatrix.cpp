#include <iostream>

using namespace std;
int abs(int j ){
if(j<0)
return -j;
return j;
}

int main()
{   
    int n,i,j;
    cout<<"Enter order of the square matrix\n";
    cin>>n;
    int *arr = new int[(3*n-2)];
    cout<<"Enter "<<3*n-2<<" elements\n";
    for(i = 0 ; i<3*n-2 ; i++)
    cin>>arr[i];
    int t = 0;
    for(i = 0 ; i<n ; i++){
        for(j = 0 ; j<n ; j++){
            if(abs(j-i)<=1)
            cout<<arr[t++]<<' ';
            else
            cout<<0<<' ';
        }
        cout<<endl;
    }

    return 0;
}
