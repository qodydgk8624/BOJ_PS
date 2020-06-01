// BOJ - 10942 펠린드롬?

#include <iostream>
#define MAXN 2000 + 1

using namespace std;

int arr[MAXN] = {0, };
int dp[MAXN][MAXN] = {0, };


int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    // length = 1
    for(int i = 1; i <= n; i++) dp[i][i] = 1;

    // length = 2
    for(int i = 1; i < n; i++)
        if(arr[i] == arr[i + 1])
            dp[i][i + 1] = 1;

    // length >= 3
    for(int i = 2; i < n; i++)
        for(int j = 1; j < n; j++)
            if(arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = 1;

    int m; cin >> m;

    for(int i = 1; i <= m; i++)
    {
        int s, e; cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}