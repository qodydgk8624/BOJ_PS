// BOJ - 11050 이항 계수 1

#include <iostream>

using namespace std;

int c(int n, int k)
{
    if(n == k || k == 0) return 1;
    else return c(n-1, k) + c(n-1, k-1);
}

int main()
{
    int n, k; cin >> n >> k;
    cout << c(n, k);
}