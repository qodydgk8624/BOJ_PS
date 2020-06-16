// BOJ - 14309

#include <stdio.h>
#include <memory.h>

#define ll long long

ll min(ll a,ll b)
{
	return a<b?a:b;
}

ll map[3001][3001];
ll dp[3001][3001];

int main()
{
	ll T,caseT=0;
	scanf("%lld",&T);
	while(T--)
	{
		++caseT;
		ll n,m,k;
		scanf("%lld %lld %lld",&n,&m,&k);

		memset(map,0,sizeof(map));
		memset(dp,0,sizeof(dp));
		
		while(k--)
		{
			ll x,y;
			scanf("%lld %lld",&x,&y);
			map[x+1][y+1]=1;
		}
		
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(map[i][j]==0)
					dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
				else
					dp[i][j]=0;
			}
		}
		ll sum=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				sum+=dp[i][j];
		
		printf("Case #%lld: %lld\n",caseT,sum);
	}
}
