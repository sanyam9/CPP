#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cout<<"Enter number of elements\n";
    cin>>n;
    int *a = new int[n];
    cout<<"Enter "<<n<<" elements\n";
    
    for (i = 0 ; i<n ; i++){
        cin>>a[i];
    }
    
    for(i = 0 ; i<n ; i++){
        for(j = 0 ; j<n ; j++){
            if(a[i] == a[j] && i!=j){
            	int t = a[n-1];
            	a[j] = a[n-1];
            	a[n-1] = a[j];
            	n--;
            }
        }
    }
    cout<<"Result:\n";
    
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<' ';}
    return 0;
}
