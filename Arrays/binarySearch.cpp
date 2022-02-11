#include <iostream>

using namespace std;

int main()
{
    int start,end,mid,n,i,val;
    cout<<"Enter number of elements\n";
    cin>>n;
    int *arr = new int[n];
    
    cout<<"Enter "<<n<<" elements for the sorted array\n";
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    start = 0;
    end=n-1;
    
    cout<<"Enter value to be searched\n";
    cin>>val;
    
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==val){
            cout<<val<<" at position "<<mid+1<<endl;
            break;
        }
        else if (arr[mid]>val)
        end = mid-1;
        else if (arr[mid]<val)
        start = mid+1;
    }
	if (start>end){
		cout<<val<<" not found!";
	}
    return 0;
}
