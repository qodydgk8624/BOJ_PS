// BOJ - 1929 소수 구하기

#include <iostream>
#define INF 0xFFFF

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int prime[m + 2] ={0, };
    for(int i = 2; i <= m; i++)
    {
        if(!prime[i])
        {
            if(n <= i) cout << i << '\n';
            for(int j = i + i; j <= m; j += i)
                prime[j] = 1;
        }
    }
}