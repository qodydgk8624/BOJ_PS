// BOJ - 2293

#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int coin[n+1]={0};
	int d[k+1]={0};
	for(int i=1; i<=n; i++)
		scanf("%d",&coin[i]);
	d[0]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
			if(j-coin[i]>=0) 
				d[j]+=d[j-coin[i]];
	
	printf("%d",d[k]);
	
}
