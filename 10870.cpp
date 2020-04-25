// BOJ - 10870 피보나치 수 5

#include <iostream>

using namespace std;

int fibo(int n)
{
    return n <= 1 ? n : fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n; cin >> n;
    cout << fibo(n);
}