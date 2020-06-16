// BOJ - 2839

#include <stdio.h>
#include <algorithm>
#define INF 987654321
int main()
{
	int N;
	scanf("%d",&N);
	int ans=INF;
	for(int x=0; x<=N/3; x++)
		if((N-x*3)/5*5+3*x==N)
			ans=min(ans,x+(N-x*3)/5);
	printf("%d",ans==INF?-1:ans);
}
