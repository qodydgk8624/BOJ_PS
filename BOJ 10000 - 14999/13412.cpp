// BOJ - 13412

#include <stdio.h>

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,r=0,i=1;
		for(scanf("%d",&n);i*i<n;)
			if(!(!(n/i*i-n)-gcd(i++,n/i)))r++;
		printf("%d\n",!(n-1)?1:r);
	}
}
