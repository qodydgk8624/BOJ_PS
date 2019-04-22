// BOJ - 1914

#include <stdio.h>

int n,printbool=1;
void print(int i,int from,int to)
{
	printf("%d %d\n",from,to);
}
long long int pow(int p)
{
	long long int res=1;
	for(int i=1; i<=p; i++)
		res*=2;
	return res;
}
void hanoi(int i,int from,int mid,int to)
{
	if(i==1)
		print(i,from,to);
	else
	{
		hanoi(i-1,from,to,mid);
		print(i,from,to);
		hanoi(i-1,mid,from,to);
	}
}
int main()
{
	scanf("%d",&n);
	printf("%lld\n",pow(n)-1);
	if(n<=20) hanoi(n,1,2,3);
}
