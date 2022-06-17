#include <bits/stdc++.h>
using namespace std;
void rec(int n, int from, int to , int via)
{
    if(n==1)
    {
        cout<<from<<" "<<to<<endl;
        return;
    }
    else
    {
        rec(n-1,from,via, to);
        rec(1,from,to,via);
        rec(n-1,via,to,from);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    rec(n,1,3,2);
    return 0;
}