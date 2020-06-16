// BOJ - 4344

#include <stdio.h>
int main()
{
	int C;
	scanf("%d",&C);
	for(int i=1; i<=C; i++)
	{
		int n;
		scanf("%d",&n);
		double a[n],avg=0;
		for(int i=0; i<n; avg+=a[i],i++)
			scanf("%lf",&a[i]);
		avg/=(double) n;
		double cnt=0;
		for(int i=0; i<n; i++)
			if(avg<a[i]) cnt++;
		printf("%.3lf%%\n",cnt/n*100);
		
	}
}
