// BOJ - 2718

#include <stdio.h>
#define MAX 100

int main()
{
	int T;
	int dp[MAX+1]={0};
	dp[1]=1,dp[2]=5,dp[3]=11;
	for(int i=4; i<=MAX; i++)
	{
		dp[i]=dp[i-1]+dp[i-2]*4+3;
		/*int val=0;
		for(int j=1; j<i; j++)
			val+=(dp[j]*dp[i-j]-1);
		dp[i]=val+4;*/
	}
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}
