// BOJ - 11401 이항 계수 3

// 페르마의 소정리 사용

#include <iostream>
#define ll long long
#define mod 1000000007

using namespace std;

ll fact(ll n)
{
    ll ret = 1;
    for(ll i = 1; i <= n; i++)
        ret = (ret * i) % mod;
    return ret;
}

ll pow(ll a, ll b)
{
    if(b == 0) return 1;
    ll t = pow(a, b / 2) % mod;
    if(b % 2) return ( ((a * t) % mod) * t ) % mod;
    else return (t * t) % mod;
}

int main()
{
    ll n, k; cin >> n >> k;
    ll A = fact(n);
    ll B = pow(fact(k) % mod, mod - 2);
    ll C = pow(fact(n - k) % mod, mod - 2);
    ll res = ((A * B) % mod) * C % mod; 
    cout << res;
}