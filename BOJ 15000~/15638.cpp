// BOJ - 15638

#include <stdio.h>
int main()
{
	int n,t=0;
	scanf("%d",&n);
	for(int i=2; i*i<=n; i++)
		if(n%i==0)
			t++;
	if(!t) puts("Yes");
	else puts("No");
}
