// BOJ - 11055

#include <stdio.h>

#define ll long long

ll D[1001],O[1001];

ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	
	
	for(int i=1; i<=n; i++)
		scanf("%lld",&O[i]);
		
	
	ll ans = 0;
	
	for(int i=1; i<=n; i++)
	{
		ll max_v=0;
		for(int j=0; j<i; j++)
		{
			if(O[j]<O[i])
				max_v=max(max_v,D[j]+O[i]);
		}
		D[i]=max_v;
		ans=max(ans,D[i]);
	}
	
	printf("%lld",ans);
}
