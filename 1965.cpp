// BOJ - 1965

#include <stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,res=0;
	scanf("%d",&n);
	int d[n+1]={0};
	int map[n+1]={0};
	for(int i=0; i<n; i++)
		scanf("%d",&map[i]);
	for(int i=0; i<n; i++)
	{
		d[i]=1;
		for(int j=0; j<i; j++)
			if(map[j]<map[i])
				d[i]=max(d[i],d[j]+1);
		res=max(res,d[i]);
	}
	printf("%d",res);
}
