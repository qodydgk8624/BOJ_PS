// BOJ - 1010

#include <stdio.h>

#define ll long long 

ll C(ll n,ll r)
{
	if(r==0||n==r) return 1;
	return C(n,r-1)*(n-r+1)/r;
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll n,m;
		scanf("%lld %lld",&m,&n);
		printf("%lld\n",C(n,m));
	}
}


