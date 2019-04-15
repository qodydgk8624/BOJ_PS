// BOJ - 1912

#include <stdio.h>

#define ll long long
#define in(n) scanf("%lld",&(n))
#define out(n) printf("%lld",(n))

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	ll n,ans;
	in(n);
	ll D[n+1]={0},O[n+1]={0};
	for(int i=1; i<=n; i++) in(O[i]);
	// D[n]= O[1]~O[N] 까지 몇개의 연속된 수를 더했을 때 나오는 가장 큰 합 
	// D[i]는 D[i-1]+O[i] 이나 O[i] 이 최댓값이 된다.
	ans=O[1];
	D[1]=max(O[1],0);
	for(int i=2; i<=n;i++)
		ans=max(ans,D[i]=max(D[i-1]+O[i],O[i]));
	out(ans);
	
}
