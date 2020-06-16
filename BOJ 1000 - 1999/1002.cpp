// BOJ - 1002

#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x1,y1,r1,x2,y2,r2;
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		int d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		int sum=r1+r2,dsum=sum*sum;
		if(x1==x2 && y1==y2 && r1==r2) puts("-1");
		else if((dsum<d1) || (r1-r2)*(r1-r2)>d1) puts("0");
		else if((dsum==d1) || (r1-r2)*(r1-r2)==d1) puts("1");
		else if(dsum>d1) puts("2");
	}
}
