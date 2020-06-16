// BOJ - 2004 조합 0의 개수

#include <stdio.h>
#define ll long long int

ll twoc[2];
ll fivec[2];

ll min(ll a,ll b)
{
	return a<b?a:b;
}
void fac_zero(ll k,ll cnt)
{
	ll two=0,five=0;
	for(ll i=2; i<=k; i*=2)
		two += k/i;
	for(ll i=5; i<=k; i*=5)
		five += k/i;
	twoc[cnt]=two;
	fivec[cnt]=five;
}
int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	fac_zero(n,0);
	fac_zero(m,1);
	fac_zero(n-m,2);
	printf("%lld",min(twoc[0]-twoc[1]-twoc[2],fivec[0]-fivec[1]-fivec[2]));
	
}