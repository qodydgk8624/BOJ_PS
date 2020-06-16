// BOJ - 11048

#include <stdio.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int arr[1001][1001];
int dp[1001][1001];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&arr[i][j]);
			
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+arr[i][j];
			
			
	printf("%d",dp[n][m]);
}
