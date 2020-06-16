// BOJ - 10872 팩토리얼

#include <iostream>

using namespace std;

int f(int n)
{
    return n <= 1 ? 1 : n * f(n - 1);
}
int main()
{
    int n; cin >> n;
    cout << f(n);
}