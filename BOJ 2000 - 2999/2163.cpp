// BOJ - 2163

#include <stdio.h>

int main()
{
	// 세로부터 자르든 , 가로부터 자르든
	// 식을 정리하게 되면 똑같다.
	// mn-1
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d",m*n-1); 
}
