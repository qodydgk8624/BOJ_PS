// BOJ - 14888 연산자 끼워넣기

#include <iostream>
#include <vector>

#define MAXN 11 + 1
#define ll long long int

using namespace std;

ll n; char oper[MAXN];
ll oper_used[MAXN] = {0, };
ll number[MAXN]={0, };
ll ans_max = -0xFFFFFFFFFF;
ll ans_min = 0xFFFFFFFFFF;

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll operate(ll a, ll b, char op)
{
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == 'x') return a * b;
    else if(op == 'd')
    {
        if(a < 0) return -(-a / b);
        else return (a / b);
    }
}

void dfs(ll idx, ll val)
{
    if(idx == n - 1) 
    {
        ans_max = max(ans_max, val);
        ans_min = min(ans_min, val);
        return;
    }

    for(int i = 0; i < n - 1; i++)
    {
        if(!oper_used[i])
        {
            oper_used[i] = 1;
            dfs(idx + 1, operate(val, number[idx + 1], oper[i]));
            oper_used[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> number[i];

    ll idx = 0;
    for(ll i = 0; i < 4; i++)
    {
        char op;
        if(i == 0) op = '+';
        else if(i == 1) op = '-';
        else if(i == 2) op = 'x';
        else if(i == 3) op = 'd'; // 나누기

        ll times = 0; cin >> times;

        for(ll j = 0; j < times; j++)
            oper[idx++] = op;
    }


    dfs(0, number[0]);

    cout << ans_max << '\n';
    cout << ans_min;
}