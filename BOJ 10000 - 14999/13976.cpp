// BOJ - 13976 

#include <stdio.h>
#define MOD 1000000007
#define ll long long

int main()
{
	ll n;
	scanf("%lld",&n);
	if(n%2)
	{
		printf("0");
		return 0;
	}
	n/=2;
	ll pp=3,p=11,cur;
	for(ll i=3; i<=n; i++)
	{
		cur=((p+MOD)*4-pp+MOD)%MOD;
		printf("%lld\n",cur);
		//printf("%lld %lld %lld\n",pp,p,cur);
		pp=p,p=cur;
	}
	printf("%lld\n",cur%MOD);
}
