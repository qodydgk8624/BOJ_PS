// BOJ - 1111
#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n==1) return -puts("B");
	if(n==2) return -puts("A");
	int d[n+1]={0},diff[n+1]={0};
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&d[i]);
		if(i>=2)
			diff[i]=d[i]-d[i-1];
	}
	
	int diff2=(!diff[2])?0:diff[3]/diff[2];
	printf("%d",d[n]+diff2*diff[n]);
	
	
}
