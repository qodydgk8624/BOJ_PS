// BOJ - 12852 1로 만들기 2

#include <iostream>
#define INF 987654321

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    
    int n; cin >> n;

    int d[n + 1] = {0, };
    int p[n + 1] = {0, };
    for(int i = 2; i <= n; i++)
    {
        int c1 = INF, c2 = INF, c3 = INF;
        if(i % 3 == 0) c1 = d[i / 3] + 1;
        if(i % 2 == 0) c2 = d[i / 2] + 1;
        c3 = d[i - 1] + 1;

        d[i] = min(min(c1, c2), c3);

        if(d[i] == c1) p[i] = i / 3;
        if(d[i] == c2) p[i] = i / 2;
        if(d[i] == c3) p[i] = i - 1; 
    }

    cout << d[n] << '\n';
    
    while(n != 1)
    {
        cout << n << ' ';
        n = p[n];
    };

    cout << 1;
    
}