// BOJ - 3009 네 번째 점

#include <iostream>

using namespace std;

int main()
{
    int x[3], y[3];
    int a, b;

    for(int i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }
    a = (x[0] == x[1]) ? x[2] : ((x[1] == x[2]) ? x[0] : x[1]);
    b = (y[0] == y[1]) ? y[2] : ((y[1] == y[2]) ? y[0] : y[1]);

    cout << a << ' ' << b;
}