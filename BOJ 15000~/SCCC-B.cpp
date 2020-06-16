// BOJ-SCCC(B)

#include <stdio.h>

#define ll int
#define MAXN 200000
ll n,q,sum=0;

ll A[MAXN*2+1];
ll Q[MAXN+1];
ll MA[MAXN+1];

void change(ll k)
{
	for(int i=k; i>=k-3; i--)
	{
		if(i>=1) sum=sum-2*MA[i],MA[i]=-MA[i];
		else sum=sum-2*MA[n+i],MA[n+i]=-MA[n+i];
	}
}

ll t(ll p)
{
	if(p>n) return p%n;
	else p;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; A[n+i]=A[i],i++)
		scanf("%d",&A[i]);
	for(int i=1; i<=q; i++)
		scanf("%d",&Q[i]);
		
	MA[1]=A[1]*A[2]*A[3]*A[4];
	
	for(int i=2; i<=n; i++)
		MA[i]=(MA[i-1]/A[i-1])*A[i+3];
	
	for(int j=1; j<=n; j++) sum+=MA[j];
	
	for(int i=1; i<=q; i++)
	{

		change(Q[i]);
		
		printf("%d\n",sum);
	}
}
