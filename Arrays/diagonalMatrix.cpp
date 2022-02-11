#include <iostream>

using namespace std;

int main()
{   
    int n,i,j;
    cout<<"Enter order of the square matrix\n";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter "<<n<<" elements\n";
    for(i = 0 ; i<n ; i++)
    cin>>arr[i];
    int t = 0;
    for(i = 0 ; i<n ; i++){
        for(j = 0 ; j<n ; j++){
            if(i==j)
            cout<<arr[t++]<<' ';
            else
            cout<<0<<' ';
        }
        cout<<endl;
    }

    return 0;
}
