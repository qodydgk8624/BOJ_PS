// BOJ - 11051

#include <iostream>
#define ll long long int
#define mod 10007

using namespace std;

ll D[1001][1001]={0};
ll f(ll n,ll k)
{
	if(D[n][k]) return D[n][k]%mod;
	if(!k || n==k) return D[n][k]=1;
	return D[n][k]=(f(n-1,k)%mod+f(n-1,k-1)%mod)%mod;
}
int main()
{
	ll n,k;
	cin >> n >> k;
	cout << f(n,k)%mod;
	
} 
