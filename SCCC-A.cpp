// BOJ - SCCC(A)

#include <stdio.h>

#define ll long long

ll max(ll a,ll b)
{
	return a>b?a:b;
}

ll n,sum,O[11]={0};

ll getValue(int a,int b,int c)
{
	// [1,a] + (a,b] + (b,c] + (c,n]
	
	ll sum=0,t=1;
	for(int i=1; i<=a; i++)
		t*=O[i];
	sum+=t;
	t=1;
	for(int i=a+1; i<=b; i++)
		t*=O[i];
	sum+=t;
	t=1;
	for(int i=b+1; i<=c; i++)
		t*=O[i];
	sum+=t;
	t=1;
	for(int i=c+1; i<=n; i++)
		t*=O[i];
	sum+=t;
	return sum;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++)
		scanf("%lld",&O[i]);
	for(int i=1; i<=n-3; i++)
		for(int j=i+1; j<=n-2; j++)
			for(int k=j+1; k<=n-1; k++)
				sum=max(sum,getValue(i,j,k));
				
	printf("%lld",sum);
}
