// BOJ - 1086 박성원

// DP + 비트마스크 문제

// https://suuntree.tistory.com/124 참조

/*

DP 셋팅?
=>  d[bit][mod]: bit를 선택해 나머지가 mod인 것들의 수

무엇을 구해야 할까?
=>  d[(1 << n) - 1][0]

전체 가짓수: n!

*/

#include <iostream>
#include <string>
#define ll long long
#define MAXN 15
#define MAX_MOD 100 + 1

using namespace std;

ll d[(1 << MAXN) + 1][MAX_MOD];
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    string astr[n];
    int a[n] = {0, }; int len[n] = {0, };
    for(int i = 0; i < n; i++)
    {
        cin >> astr[i]; len[i] = astr[i].size();
    }
    int k; cin >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < len[i]; j++)
            a[i] = (a[i] * 10 + (astr[i][j] - '0')) % k;

    int pow[51] = {1, };
    for(int i = 1; i < 51; i++)
        pow[i] = (pow[i - 1] * 10) % k;

    d[0][0] = 1;
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < k; j++)
            for(int l = 0; l < n; l++)
                if((i & (1 << l)) == 0)
                {
                    int next = (a[l] + j * pow[len[l]]) % k;
                    d[i | (1 << l)][next] += d[i][j];
                }

    ll p = d[(1 << n) - 1][0];
    ll q = 1; for(ll i = 2; i <= n; i++) q *= i; // n! 구현
    ll g = gcd(p, q); p /= g; q /= g;
    cout << p << '/' << q;
}