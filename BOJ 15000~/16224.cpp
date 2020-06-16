// BOJ - 16224

#include <stdio.h>

void p(int n,int m)
{
	printf("%d %d\n",n,m);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==m)
    {
        printf("%d\n",n*n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                printf("%d %d\n",i,j);
    }
    else if(n==3 && m==1)
    {
    	printf("%d\n",6);
    	p(1,1);p(2,2);p(3,3);
    	p(1,2);p(2,3);p(3,1);
	}
	else if(n==4 && m==2)
	{
		printf("%d\n",8);
		p(1,2);p(2,1);
		p(2,3);p(3,2);
		p(3,4);p(4,3);
		p(4,1);p(1,4);
	}
    else printf("-1");
}
