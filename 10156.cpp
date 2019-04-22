// BOJ - 10156

#include <stdio.h>
int main()
{
	int n,m,k,res;
	scanf("%d%d%d",&n,&m,&k);
	res=n*m-k;
	if(res>0) printf("%d",res);
	else printf("%d",0);
}
