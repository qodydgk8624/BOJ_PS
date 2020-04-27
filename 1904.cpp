// BOJ - 1904 01타일

#include <iostream>
#define MOD 15746
#define MAXN 1000000 + 1
#define ll long long int

int n; int dp[MAXN] = {0,};

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    
    cin >> n;
    dp[1] = 1, dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[n];
}