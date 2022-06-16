#include <bits/stdc++.h>
using namespace std;
// 0 1 1 2 3 5 8 13 21 ...
//using recursion O(2^n)

int fibonacci(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
// using for loop O(n)
int fib(int n)
{
    int a=0,b=1;
    if(n<=1) return n;
    for(int i=2;i<=n;i++)
    {
        int temp=b;
        b=a+b;
        a=temp;
    }
    return b;
}
int main()
{
	cout<<fibonacci(9)<<" "<<fib(9)<<endl;
}