// BOJ - 17121

#include <iostream>
#include <vector>

#define MAXN 1000000

using namespace std;

vector<int> s;

int sieve[MAXN+1]={1,1,0};

int weakcon[MAXN*3]={0};

void SieveCalc()
{
	for(int i=2; i*i<=MAXN; i++)
	{
		if(!sieve[i])
		{
			for(int j=i+i; j<=MAXN; j+=i)
				sieve[j]=1;
		}
	}
	for(int i=2; i<=MAXN; i++)
		if(!sieve[i])
			s.push_back(i);
}

void GWC() // °ñµå¹ÙÈåÀÇ ¾àÇÑ ÃßÃø 
{

	for(int i=0; i<s.size(); i++)
		for(int j=i; j<s.size(); j++)
		{
			for(int k=j; k<s.size(); k++)
			{
				if(s[i]+s[j]>s[k])
					weakcon[s[i]+s[j]+s[k]]++;
				else break;
			}
		}
	
}

int main()
{
	SieveCalc();
	
	GWC();
	
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int N;
		scanf("%d",&N);
		printf("%d\n",weakcon[N]);
	}
	
	
}
