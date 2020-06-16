// BOJ - 11653 소인수분해

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 2; i * i <= n; i++)
        while(n % i == 0)
        {
            cout << i << '\n';
            n /= i;
        }    

    if(n > 1) cout << n << '\n';
}