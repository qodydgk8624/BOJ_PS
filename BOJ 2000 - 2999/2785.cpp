// BOJ - 2785

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 500000

int main()
{
	int n,s=0,a[MAXN+1],c;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);	
	for(int i=1; i<=n; i++)
	{	
		c=n-i,s+=a[i];
		if(s>=c){printf("%d",c);break;}
	}
}
