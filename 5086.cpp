// BOJ - 5086 배수와 약수

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    while(1)
    {
        int a, b; cin >> a >> b;
        if(!a & !b) return 0;
        if(a % b == 0) cout << "multiple" << '\n';
        else if(b % a == 0) cout << "factor" << '\n';
        else cout << "neither" << '\n';
    }
}