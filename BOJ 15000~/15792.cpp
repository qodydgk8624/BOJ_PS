// BOJ - 15792

#include <stdio.h>
int main()
{
	int a,b,_do=1500;
	scanf("%d%d",&a,&b);
	int q=(int) a/b; // ¸ò
	printf("%d.",q);
	int rest= a%b; // ³ª¸ÓÁö 
	while(_do--)
	{
		rest*=10;
		printf("%d",(int) rest/b);
		rest%=b;
		if(!rest) return 0;
	}
}
