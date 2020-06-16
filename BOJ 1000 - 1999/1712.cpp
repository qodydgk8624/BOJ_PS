// BOJ - 1712 순익분기점
#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",c<=b?-1:a/(c-b)+1);
} 