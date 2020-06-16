// BOJ - 2133

#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n%2)
	{
		printf("0");
		return 0;
	}
	int D[n+1]={1,0,3};
	for(int i=4; i<=n; i+=2)
	{
		D[i]=D[i-2]*3;
		for(int j=4; i-j>=0; j+=2)
			D[i]+=D[i-j]*2;
	}
	
	printf("%d",D[n]);
}
