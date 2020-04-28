// BOJ - 3036 링

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int d[n] = {0, };
    for(int i = 0; i < n; i++) cin >> d[i];

    for(int i = 1; i < n; i++)
    {
        int g = gcd(d[0], d[i]);
        cout << d[0] / g << '/' << d[i] / g << '\n';
    }
}