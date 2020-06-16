// BOJ - 1110

#include <stdio.h>

int main()
{
	int ori,f,n,move=1;
	scanf("%d",&ori);
	f=ori;
	n=((f/10)+(f%10))%10+(f%10)*10;
	while(n!=ori)
	{
		f=n;
		n=((f/10)+(f%10))%10+(f%10)*10;
		move++;
	}
	printf("%d",move);
	
}
