#include <bits/stdc++.h>
using namespace std;
int main()
{
    //creating array of size row X col
    int row,col;
    cin>>row>>col;
    //creating  2-d array
    int ** arr=new int*[row];
    // int * means one array and int *[row] means (row) number of arrays 
    // eg int *[5] means 5 1-d arrays
    
    for(int i=0;i<row;i++)
    {
        arr[i]= new int[col];
    }

    // inputing values in arrays
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    // printing values

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // deleting heap memory
    for(int i=0;i<row;i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
    return 0;
}