// BOJ - 2482 색상환

#include <iostream>
#define mod 1000000003

using namespace std;

/*
    d[i][j] = "i개의 색생환을 조건에 맞게 j개 색칠하는 경우"
*/
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    int d[1001][1001] = {0, };

    d[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        d[i][0] = 1; d[i][1] = i;
    }

    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= k; j++)
            d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % mod;

    d[n][k] = (d[n - 1][k] + d[n - 3][k - 1]) % mod;

    cout << d[n][k];
}