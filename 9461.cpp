// BOJ - 9461

#include <stdio.h>

#define ll long long

int main()
{
	ll d[101]={0,1,1,1};
	for(int i=4; i<=100; i++)
		d[i]=d[i-2]+d[i-3];
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",d[n]);
	}
}
