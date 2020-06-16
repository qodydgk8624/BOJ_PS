// BOJ - 14501

#include <stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int T[n+1]={0};
	int P[n+1]={0};
	for(int i=1; i<=n; i++)
		scanf("%d %d",&T[i],&P[i]);
	int dp[50]={0},ans=0;
	for(int i=1; i<=n+1; i++)
	{
		dp[i]=max(ans,dp[i]);
		dp[i+T[i]]=max(dp[i+T[i]],dp[i]+P[i]);
		ans=max(ans,dp[i]);
	}

	printf("%d",ans);
	
}
