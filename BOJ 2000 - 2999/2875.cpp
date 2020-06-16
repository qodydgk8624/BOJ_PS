// BOJ - 2875

#include <stdio.h>

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	printf("%d",min(min(n/2,m),(n+m-k)/3));
}
