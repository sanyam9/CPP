#include <iostream>

using namespace std;

int* createArr(int s){
    int *arr = new int[s];
    for (int i = 0 ; i<s ; i++){
        cin>>arr[i];
    }
    return arr;
}
void displayArr(int *arr , int s){
    for (int i = 0 ; i<s ; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
int * insertArr(int *arr, int idx, int val, int s){
    int *ar = new int[s];
    for (int i = 0 ; i<s-1;i++){
        ar[i]=arr[i];
    }
    for( int i = s-1 ; i>idx ; i--){
        ar[i]=ar[i-1];
    }
    ar[idx] = val;
    return ar;
}
int * deleteArr(int *arr, int val , int s){
    int idx;
    int *ar = new int[s];
    for (int i = 0 ; i<s+1;i++){
        if (arr[i] == val){
            idx = i;
            break;
        }
    }    
    if (idx<=s){
        for (int i = 0 ; i<idx ; i++)
        ar[i] = arr[i];
        for(int i = idx ; i<s ; i++)
        ar[i] =arr[i+1];
        return ar;
    }
    return arr;
}
int searchArr(int *arr, int val , int s){
    int idx=-1;
    for (int i = 0 ; i<s;i++){
        if (arr[i] == val){
            idx = i;
            return idx+1;
        }
    }
    return idx;
}
int main(){   
	int op,n,val,idx,i;
    char ch = 't';
    int *arr;
    cout<<"---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.SEARCH\n6.EXIT\n";
    
    while(ch=='t'){
        cout<<"Enter an option\n";
        cin>>op;
        switch(op){
            case 1: 
                cout<<"Enter number of elements\n";
                cin>>n;
                arr = createArr(n);
                break;
            case 2:
                displayArr(arr,n);
                break;
            case 3:
                cout<<"Enter the value of the new element and the index\n";
                cin>> val>>idx;
                n++;
                arr = insertArr(arr,idx,val,n);
                break;
            case 4:
                cout<<"Enter the value of the element to be deleted\n";
                cin>>val;
                idx = searchArr(arr,val,n);
                if(idx != -1){
                n--;
                arr = deleteArr(arr,val,n);}
                else
                cout<<val<<" not found!\n";
                break;
            case 5:
                cout<<"Enter the value to be searched\n";
                cin>>val;
                idx = searchArr(arr,val,n);
                if(idx == -1)
                cout<<val<<" not found!\n";
                else
                cout<<val<<" found at "<<idx<<" position\n";
                break;
            case 6:
                ch = 'f';
        }
        
    }
    cout<<"--EXIT--";
    return 0;
}
