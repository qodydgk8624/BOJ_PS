// BOJ - 2565 전깃줄

#include <iostream>
#include <algorithm>

using namespace std;

struct p {
    int a, b;
    bool operator<(const p X)
    {
        return a < X.a;
    }
    bool operator>(const p X)
    {
        return a > X.a;
    }
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n; cin >> n;
    p o[n];

    for(int i = 0; i < n; i++)
        cin >> o[i].a >> o[i].b;

    sort(o, o + n);

    int dp[n] = {0, };

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int temp = 1;
        for(int j = 0; j < i; j++)
            if(o[j].b < o[i].b)
                temp = max(temp, dp[j] + 1);
        dp[i] = temp;
        ans = max(ans, dp[i]);
    }

    cout << n - ans;


    
}