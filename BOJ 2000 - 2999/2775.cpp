// BOJ - 2775 부녀회장이 될테야

#include <stdio.h>
int D[15][15]={0,};
int f(int a,int b)
{
	int k=b,s=0;
	if(D[a][b]) return D[a][b];
	if(a==1) return D[a][b]=(b*b+b)/2;
	for(;b>0;b--) s+=(D[a-1][b]=f(a-1,b));
	return D[a][k]=s;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",f(a,b));
	}
}