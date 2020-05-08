//
//           1072 - 게임
//

// Z가 절대 안 변하는 경우 : 99%,100%

#include <stdio.h>

#define ll long long int
int main()
{
	ll x,y,z,q,l=0,r=1e9,m;
	scanf("%lld %lld",&x,&y);
	z=y*100/x;
	if(z>=99)
		puts("-1");
	else
	{
		while(l<=r)
			m=(l+r)/2,q=100*(y+m)/(x+m),z<q?r=m-1:l=m+1;
		printf("%lld",l);
	}
} 