// BOJ - 2225

#include <stdio.h>

#define ll long long
#define mod 1000000000

ll D[201][201]={0};

int main()
{
	ll n,k;
	scanf("%lld%lld",&n,&k);
	
	for(int i=0; i<=n; i++)
		D[i][1]=1;
		
	for(int i=2; i<=k; i++)
		for(int j=0; j<=n; j++)
			D[j][i]=j==0?1:(D[j-1][i]+D[j][i-1])%mod;
			
	printf("%lld",D[n][k]%mod);
	
}


