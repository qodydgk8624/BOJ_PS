// BOJ - 9020 골드바흐의 추측

#include <iostream>
#define INF 0xFFFF
#define MAXN 10000

using namespace std;

int main()
{
    int n; cin >> n;
    int prime[MAXN + 2] ={0, };
    for(int i = 2; i <= MAXN; i++)
    {
        if(!prime[i])
            for(int j = i + i; j <= MAXN; j += i)
                prime[j] = 1;
    }

    while(n--)
    {
        int k; cin >> k;
        int prev = 0;
        for(int i = 2; i <= k - i; i++)
            if(!prime[i] & !prime[k - i])
                if(prev < i) prev = i;

        cout << prev << ' ' << k - prev << '\n';
    }
}