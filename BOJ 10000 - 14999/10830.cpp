// BOJ - 10830 행렬 제곱

#include <iostream>
#define ll long long
#define mod 1000

using namespace std;

ll n;

ll a[6][6] = {0, };
ll ans[6][6] = {0, };

void multiply(ll a[6][6], ll b[6][6])
{
    ll c[6][6] = {0, };
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = c[i][j];
    
}
int main()
{
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ans[i][i] = 1, i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
 
    while(k > 0)
    {
        if (k % 2) multiply(ans, a);
        multiply(a, a); k /= 2;
    }
    
    for (int i = 1; i <= n; puts(""), i++)
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
}