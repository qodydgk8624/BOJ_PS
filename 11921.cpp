// BOJ - 11921

#include <stdio.h>

#define ll long long

int main()
{
	ll i=1,n,k,s=0;
	scanf("%lld",&n);
	if(n>1000000) n=1000000;
	for(; i<=n; s+=k,i++) scanf("%lld",&k);
	printf("%lld\n%lld",n,s);
}


