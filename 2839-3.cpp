// BOJ - 2839 Short Coding Ex ver.

#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=3; i<=n; i++)
		printf("%d\n",i-4&&i-7?i-2*i/5*2:-1);
}
