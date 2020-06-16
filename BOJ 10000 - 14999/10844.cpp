// BOJ - 10844

#include <stdio.h>

#define ll long long
#define mod 1000000000
int main()
{
	ll n;
	scanf("%lld",&n);
	ll D[n+1][11]={0},sum=0;
	for(int i=1; i<=n; i++)
	{
		if(i==1) for(int j=1; j<=9; D[i][j]=1,j++);
		else 
			for(int j=0; j<=9; j++)
				D[i][j]=((!j?0:D[i-1][j-1])+D[i-1][j+1])%mod;
		if(i==n) for(int j=0; j<=9; j++) sum+=(D[i][j]%mod);
	}
	printf("%lld",sum%mod);
}
