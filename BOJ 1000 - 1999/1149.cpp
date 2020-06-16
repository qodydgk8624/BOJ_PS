// BOJ - 1149

// 집의 이웃은 같은 색이면 안된다.

#include <stdio.h>

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int R[n+1]={0};
	int G[n+1]={0};
	int B[n+1]={0};
	int dp[4][n+1]={0};
	for(int i=1; i<=n; i++)
		scanf("%d %d %d",&R[i],&G[i],&B[i]);
	dp[1][1]=R[1],dp[2][1]=G[1],dp[3][1]=B[1];
	for(int i=2; i<=n; i++)
	{
		dp[1][i]=min(dp[2][i-1],dp[3][i-1])+R[i];
		dp[2][i]=min(dp[1][i-1],dp[3][i-1])+G[i];
		dp[3][i]=min(dp[1][i-1],dp[2][i-1])+B[i];
	}
	printf("%d",min(min(dp[1][n],dp[2][n]),dp[3][n]));
} 
