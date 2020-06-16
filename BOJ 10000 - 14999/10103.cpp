// BOJ - 10103

#include <ios>

int main()
{
	int n;
	scanf("%d",&n);
	int a=100,b=100;
	for(int i=1; i<=n; i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		if(t1<t2) a-=t2;
		if(t1>t2) b-=t1;
	}
	printf("%d\n%d",a,b);
}
