// BOJ - 9465

#include <stdio.h>

#define ll long long 

ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll T;
	scanf("%lld",&T);

	while(T--)
	{
		ll n,ans=0;
		scanf("%lld",&n);
		
		ll D[n+1][2]={0},O[n+1][2]={0};
		for(int j=0; j<2; j++)
			for(int i=1; i<=n; i++)
				scanf("%lld",&O[i][j]);
		D[1][0]=O[1][0],D[1][1]=O[1][1];
		for(int i=2; i<=n; i++)
		{
			D[i][0]=max(D[i-1][1],D[i-2][1]) + O[i][0];
			D[i][1]=max(D[i-1][0],D[i-2][0]) + O[i][1];
		}
				
		printf("%lld\n",max(D[n][0],D[n][1]));
	}
}
