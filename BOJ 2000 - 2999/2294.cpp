// BOJ - 2294 

#include <stdio.h>
#define INF 987654321

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,val;
	scanf("%d %d",&n,&val);
	int coin[n+1]={0},dp[val+1]={0};
	for(int i=1; i<=val; i++)
		dp[i]=INF;
	for(int i=1; i<=n; i++)
		scanf("%d",&coin[i]);
	for(int i=1; i<=val; i++)
	{
		for(int j=1; j<=n; j++)
			if(i-coin[j]>=0)
				dp[i]=min(dp[i],dp[i-coin[j]]+1);
	}
	
	/*puts("dp arraylist");
	for(int i=0; i<=val; i++)
		printf("%d ",dp[i]);
	puts("");*/
	
	if(dp[val]==INF) printf("-1");
	else printf("%d",dp[val]);
}
