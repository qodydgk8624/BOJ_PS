// BOJ - 9095

#include <stdio.h>

int main()
{
	int dp[11]={0,1,2,4};
	for(int i=4; i<=11; i++)
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}
