// BOJ - 5557

#include <iostream>

using namespace std;

int r(long long n)
{
	return 0<=n&&n<=20;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long a[n+1]={0},dp[n+1][21]={0};
	for(int i=1; i<=n; i++)
		cin >> a[i];
	// dp[i][j] = "i번째 수를 이용해서 j를 만드는 경우의수"
	dp[1][a[1]]=1;
	for(int i=2; i<n; i++)
	{
		for(int j=0; j<=20; j++)
		{
			if(dp[i-1][j])
			{
				if(r(j+a[i])) dp[i][j+a[i]] += dp[i-1][j];
				if(r(j-a[i])) dp[i][j-a[i]] += dp[i-1][j];
			}
		}
	} 
	cout << dp[n-1][a[n]];
}
