// BOJ - 9498

#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	if(90<=n) puts("A");
	else if(80<=n) puts("B");
	else if(70<=n) puts("C");
	else if(60<=n) puts("D");
	else puts("F");
}
