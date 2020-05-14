// BOJ - 1629 곱셈

#include <iostream>
#define ll long long int

using namespace std;

ll A, B, C;

ll pow(ll n, ll p)
{
    if(p == 0) return 1;
    ll t = pow(n, p / 2) % C;
    if(p % 2)
        return ((t * t) % C) * n;
    else
        return (t * t) % C;
    

}

int main()
{
    cin >> A >> B >> C;

    cout << pow(A, B) % C;
}