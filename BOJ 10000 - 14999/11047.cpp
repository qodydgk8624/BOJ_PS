// BOJ - 11047

#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int d[n];
	for(int i=0; i<n; i++)
		cin >> d[i];
	int ans = 0;
	for(int i=n-1; i>=0; i--)
	{
		ans += (k/d[i]);
		k%=d[i];
	}
	cout << ans;
}
