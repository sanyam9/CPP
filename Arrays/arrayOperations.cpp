#include <iostream>

using namespace std;

int main()
{   int op,n,val,idx,i;
    char ch = 't';
    int arr[100];
    cout<<"---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.SEARCH\n6.EXIT\n";
    
    while(ch=='t'){
        cout<<"Enter an option\n";
        cin>>op;
        switch(op){
            case 1: 
                cout<<"Enter number of elements\n";
                cin>>n;
                cout<<"Enter "<<n<<" elements for the array\n";
                for(i = 0 ; i<n ; i++){
                    cin>>arr[i];
                }
                break;
            case 2:
                for(i = 0 ; i<n ; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
            case 3:
                cout<<"Enter the value of the new element and the index\n";
                cin>> val >> idx;
                n++;
                for( i = n-1 ; i>idx ; i--){
        			arr[i]=arr[i-1];
    			}
				arr[idx]=val;
                break;
            case 4:
                cout<<"Enter the value of the element to be deleted\n";
                cin>>val;
                idx = -1;
                for( i = 0 ; i<n ; i++){
                    if(arr[i] == val){
                        idx = i;
                        break;
                    }
                }
                if (idx!= -1){
                    n--;
                    for(i = idx ; i<n ; i++){
                        arr[i] = arr[i+1];
                    }}
                else{
                cout<<val<<" not found!\n";}
                break;
            case 5:
                cout<<"Enter the value to be searched\n";
                cin>>val;
                for( i = 0 ; i<n ; i++){
                    if(arr[i]==val){
                        cout<<val<<" found at "<<i+1<<" position\n";
                        break;
                    }
                }
                if(i>=n)
                cout<<val<<" not found!\n";
                break;
            case 6:
                ch = 'f';
        }
        
    }
    cout<<"--EXIT--";
    return 0;
}
