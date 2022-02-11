/* Addition of Two Sparse Matrices(Triplet)
Input - 	 R C V           R C V
			{0,2,2}			{0,0,2}
            {0,3,4}    + 	{0,3,1}
            {2,1,5}			{1,2,6}
            {2,3,6} 		{1,3,2}
            				{2,3,1}
Output -     R C V
			{0,0,2}
			{0,2,2}
			{0,3,5}
			{1,2,6}
			{1,3,2}
			{2,1,5}
			{2,3,7} */
			
#include <iostream>

using namespace std;

int main()
{   int r, col,n1,n2;
    cout<<"Enter number of rows and columns\n";
    cin>>r>>col;
    cout<<"Enter number of non zero elements for 1st Matrix\n";
    cin>>n1;
    cout<<"Enter number of non zero elements for 2nd Matrix\n";
    cin>>n2;
    
    int a[n1][3];
    int b[n2][3];
    
    cout<<"Enter triplet representation for 1st matrix\n";
    cout<<"R "<<"C "<<"V\n";
    for(int i = 0; i<n1;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];    
    
    
    cout<<"Enter triplet representation for 2nd matrix\n";
    cout<<"R "<<"C "<<"V\n";
    for(int i = 0; i<n2;i++)
        cin>>b[i][0]>>b[i][1]>>b[i][2];    
    
    int i=0,j=0,k=0;
    int c[n1+n2][3];
    while(i<r || j<col){
        if(a[i][0]==b[j][0]){
            
            if(a[i][1]==b[j][1]){
	            c[k][0]=a[i][0];
	            c[k][1]=a[i][1];
	            c[k][2]=a[i][2]+b[j][2];
	            i++;j++;k++;
			}
            
            else if(a[i][1]<b[j][1]){
                c[k][0]=a[i][0];
                c[k][1]=a[i][1];
                c[k][2]=a[i][2];
                i++;k++;
            }
            
            else{
                c[k][0]=b[j][0];
                c[k][1]=b[j][1];
                c[k][2]=b[j][2];
                j++;k++;
            }
        }
        else{
            if(a[i][0]<b[j][0]){
                c[k][0]=a[i][0];
                c[k][1]=a[i][1];
                c[k][2]=a[i][2];
                i++;k++;
            }
            else{
                c[k][0]=b[j][0];
                c[k][1]=b[j][1];
                c[k][2]=b[j][2];
                j++;k++;
            }
        }
    }
    cout<<"Triplet representation of the summation:\n";
    cout<<"R "<<"C "<<"V\n";
    for(i=0;i<k;i++)
    cout<<c[i][0]<<" "<<c[i][1]<<" "<<c[i][2]<<endl;
        return 0;
}        				
