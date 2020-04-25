// BOJ - 2581 소수

#include <iostream>
#define INF 0xFFFF

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int min_prime = INF, prime_sum = 0;
    int prime[m + 2] ={0, };
    for(int i = 2; i <= m; i++)
    {
        if(!prime[i])
        {
            if(n <= i) prime_sum += i;
            if(n <= i && min_prime == INF) min_prime = i;
            for(int j = i + i; j <= m; j += i)
                prime[j] = 1;
        }
    }
    if(min_prime == INF) cout << "-1";
    else cout << prime_sum << '\n' << min_prime;
}