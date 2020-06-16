// BOJ - 2749 피보나치 수 3

#include <iostream>
#define ll long long
#define mod 1000000
#define SIZE 2 + 1

using namespace std;

ll n;

ll a[SIZE][SIZE] = {0, };
ll ans[SIZE][SIZE] = {0, };

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE])
{
    ll c[6][6] = {0, };
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            for (int k = 1; k < SIZE; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            a[i][j] = c[i][j];
    
}
int main()
{
    cin >> n;
    for (int i = 1; i < SIZE; ans[i][i] = 1, i++);

    a[1][1] = 1;
    a[1][2] = 1;
    a[2][1] = 1;
    a[2][2] = 0;

    while(n > 0)
    {
        if (n % 2) multiply(ans, a);
        multiply(a, a); n /= 2;
    }

    cout << ans[1][2] % mod;
    
    
}