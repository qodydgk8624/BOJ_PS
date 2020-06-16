// BOJ - 1699

#include <stdio.h>
#define INF 987654321

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	int dp[n+1]={0,1,2};
	
	for(int i=3; i<=n; i++)
	{
		int min_v=i;
		for(int j=1; j*j<=i; j++)
			min_v=min(min_v,dp[i-j*j]+1);
		dp[i]=min_v;
	}
	printf("%d",dp[n]);
}
