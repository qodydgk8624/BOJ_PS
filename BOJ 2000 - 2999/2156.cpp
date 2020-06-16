// BOJ - 2156

#include <iostream>
#define ll long long

using namespace std;

ll max(ll a,ll b)
{
	return a>b?a:b;
}
int main()
{
	ll n;
	cin >> n;
	ll D[n+1]={0},O[n+1]={0};
	for(int i=1; i<=n; i++) cin >> O[i];
	D[1]=O[1],D[2]=O[1]+O[2];
	for(int i=3; i<=n; i++)
		D[i]=max(D[i-1],max(D[i-2]+O[i],D[i-3]+O[i-1]+O[i]));
	ll ans=0;
	for(int i=1; i<=n; i++) ans=max(ans,D[i]);
	cout << ans;
}
