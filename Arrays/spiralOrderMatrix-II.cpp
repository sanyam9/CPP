#include <iostream>
using namespace std;

int main()
{	int m,n;
	cout<<"Enter number of rows and columns\n";
	cin>>m>>n;
	cout<<"Enter "<<m*n<<" elements\n";
	int arr[m*n];
	for(int i=0; i<m*n; i++)
	cin>>arr[i];
	
	int mat[m][n];
	
	int top = 0, bottom = m - 1;
	int left = 0, right = n - 1;

	int index = 0;

	while (1)
	{
		if (left > right)
			break;
		for (int i = left; i <= right; i++)
			mat[top][i] = arr[index++];
		top++;

		if (top > bottom)
			break;

		for (int i = top; i <= bottom; i++)
			mat[i][right] = arr[index++];
		right--;

		if (left > right)
			break;
	
		for (int i = right; i >= left; i--)
			mat[bottom][i] = arr[index++];
		bottom--;

		if (top > bottom)
			break;
		
		for (int i = bottom; i >= top; i--)
			mat[i][left] = arr[index++];
		left++;
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout<< mat[i][j]<<" ";
		cout <<'\n';
	}

	return 0;
}
