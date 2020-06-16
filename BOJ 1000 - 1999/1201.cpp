// BOJ - 1201

#include <stdio.h>
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,m,k,idx=0,i=1,j;
	scanf("%d%d%d",&n,&m,&k);
	if(m+k-1>n || n>m*k) return !printf("-1");
	for(;i<=m;idx=min(idx+k,n-m+i),i++)
		for(j=min(idx+k,n-m+i)-1;j>=idx;j--) printf("%d ",j+1);
}
