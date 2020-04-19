// BOJ - 11021

#include <stdio.h>
int main()
{
	int n,i=1;
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",i,a+b);
		i++;
	}
 } 
