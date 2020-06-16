// BOJ - 11726

#include<cstdio>
#define MOD 10007

int main()
{
	int n;
	scanf("%d",&n);
	int D[n+1];
	D[1]=1,D[2]=2;
	for(int i=3; i<=n; i++)
		D[i]=(D[i-1]+D[i-2])%MOD;
	printf("%d",D[n]%MOD);
}
