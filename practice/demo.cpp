#include <bits/stdc++.h>
using namespace std;
int main()
{
	int row;
    cin>>row;
    int **arr=new int* [row];
    int col[row];
    for(int i=0;i<row;i++) cin>>col[i];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col[i];j++)
        arr[i]=new int [col[i]];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col[i];j++)
        {
            // int temp;
            // cin>>temp;
            // arr[i][j]=temp;
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col[i];j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<row;i++)
    {
        delete []arr[i];
    }
    delete []arr;
}