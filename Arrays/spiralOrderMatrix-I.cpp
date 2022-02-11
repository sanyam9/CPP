#include <iostream>

using namespace std;

int main()
{   int m,n;
    cout<<"Enter number of rows and columns\n";
    cin>>m>>n;
    
    int arr[m][n];
    for(int i = 0 ; i<m ; i++ ){
        cout<<"Enter "<<n<<" elements for row "<<i+1<<endl;
        for(int j = 0 ; j<n ; j++)
        cin>>arr[i][j];
    }
    cout<<"Output:\n";
    int top = 0, bottom = m-1, left = 0, right = n-1;
    int dir = 1;
    

    while (top <= bottom && left <= right) {
        if (dir == 1) {    
            for(int i = left; i <= right; ++i) 
                cout<<arr[top][i]<<" ";
            
            ++top;
            dir = 2;
        } 
        else if (dir == 2) 
        {     
            for (int i = top; i <= bottom; ++i) 
                cout<<arr[i][right]<<" ";
            
            --right;
            dir = 3;
        } 
        else if (dir == 3) {     
            for (int i = right; i >= left; --i) 
                cout<<arr[bottom][i]<<" ";
            
            --bottom;
            dir = 4;
        } 
        else if (dir == 4) {    
            for (int i = bottom; i >= top; --i) 
                cout<<arr[i][left]<<" ";
            
            ++left;
            dir = 1;
        }
    }
}
