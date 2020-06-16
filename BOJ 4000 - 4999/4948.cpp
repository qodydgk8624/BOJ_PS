//
//			4948 - 베르트랑 공준
//

// 2N<=246912

#include <iostream>

#define maxn 246912

using namespace std;

int isnt_prime[maxn+1]={1,1,0};

int prime_sum[maxn+1]={0};

int main()
{
	for(int i=2; i<=maxn; i++)
		if(!isnt_prime[i])
			for(int j=2*i; j<=maxn; j+=i)
				isnt_prime[j]=1;
	for(int i=2; i<=maxn;)
	{
		prime_sum[i]=prime_sum[i-1];
		if(!isnt_prime[i++])
			prime_sum[i-1]++;
	}
	int _t;
	while(1)
	{
		cin >> _t;
		if(!_t) break;
		cout << prime_sum[_t*2]-prime_sum[_t] << "\n";
	}
	
}

