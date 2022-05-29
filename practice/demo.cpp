#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool isPrime(int n)
{
    if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        bool check=true;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                check=false;
                return false;
            }
        }
        return true;
    }
}
int32_t main()
{
	string s;
	cin>>s;
	int ans=0;
    for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]-=32;
			ans+=s[i];
		}
		else 
		{
			s[i]+=32;
			ans-=s[i];
		}
		// ans+=(s[i]);
	}
	// cout<<ans<<endl;
	ans=abs(ans);
	if(isPrime(ans)) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
