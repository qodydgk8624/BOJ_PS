// BOJ - 11727

#include <stdio.h>

#define ll long long

int main()
{
	ll n;
	scanf("%lld",&n);
	ll D[n+1]={0};
	D[1]=1,D[2]=3;
	for(int i=3; i<=n; i++)
		D[i]=(D[i-1]+2*D[i-2])%10007;
	printf("%lld",D[n]);
}
