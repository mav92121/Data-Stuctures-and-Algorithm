#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //creating 1-d array
    // int * means one array
    int * arr=new int[n];
    // inputing values in array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //printing array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //deleting heap memory;
    delete []arr;
    return 0;
}