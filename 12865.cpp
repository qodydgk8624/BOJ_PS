// BOJ - 12865 평범한 배낭

#include <iostream>
#define MAXN 100 + 1
#define MAXK 100000 + 1

using namespace std;

int dp[MAXN][MAXK];
int w[MAXN], v[MAXN];

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, k; cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][k];
}
