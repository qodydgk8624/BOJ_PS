// BOJ - 1057 토너먼트

#include <stdio.h>
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int cnt=0;
	while(x!=y) x=(x+1)/2,y=(y+1)/2,cnt++;
	printf("%d",cnt);
}