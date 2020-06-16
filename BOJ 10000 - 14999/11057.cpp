// BOJ - 11057

#include <stdio.h>
#define mod 10007

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	int d[n+1][10]={0};
	for(int i=0; i<=9; i++) d[1][i]=1;
	
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<=9; j++)
		{
			int sum=0;
			for(int k=0; k<=j; k++) sum+=d[i-1][k]%mod;
			d[i][j]=sum%mod;
		}
	}
	
	for(int i=0; i<=9; i++) ans+=d[n][i]%mod;
	printf("%d",ans%mod);
}
