#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   if(n==1) cout<<0<<endl;
   else if(n==2) cout<<0<<" "<<1<<endl;
   else 
   {
       int a=0,b=1;
       int temp;
       cout<<a<<" "<<b<<" ";
       for(int i=3;i<=n;i++)
       {
           temp=a+b;
           cout<<temp<<" ";
           a=b;
           b=temp;
       }
   }
   return 0;
}