// BOJ - 11052

#include <stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	int D[n+1]={0},O[n+1]={0};
	for(int i=1; i<=n; i++)
		scanf("%d",&O[i]);
	D[1]=O[1];
	for(int i=2; i<=n; i++)
		for(int j=1; j<=i; j++)
			D[i]=max(D[i],D[i-j]+O[j]);
	printf("%d",D[n]);
}
