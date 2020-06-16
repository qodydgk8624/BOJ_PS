// BOJ - 2167

#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n+1][m+1]={0};
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&arr[i][j]);
			
	int dp[n+1][m+1]={0};
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
			
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1-=1,y1-=1;
		printf("%d\n",dp[x2][y2]-dp[x1][y2]-dp[x2][y1]+dp[x1][y1]);
	}
}
