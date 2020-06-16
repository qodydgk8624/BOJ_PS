// BOJ - 2193

#include <stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int d[n+1][2]={0};
	d[1][0]=0;d[1][1]=1;
	for(int i=2; i<=n; i++)
		d[i][0]=d[i-1][0]+d[i-1][1],d[i][1]=d[i-1][0];
	printf("%lld",d[n][0]+d[n][1]);
}
