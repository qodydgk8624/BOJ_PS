// BOJ - 2740 행렬 곱셈

#include <iostream>

using namespace std;

int main()
{
    //cin.tie(0); ios::sync_with_stdio(false);
    int an, am; cin >> an >> am;

    int A[an + 1][am + 1] = {0, };

    for(int i = 1; i <= an; i++)
        for(int j = 1; j <= am; j++)
            cin >> A[i][j];

    int bn, bm; cin >> bn >> bm;

    int B[bn + 1][bm + 1] = {0, };

    for(int i = 1; i <= bn; i++)
        for(int j = 1; j <= bm; j++)
            cin >> B[i][j];

    for(int i = 1; i <= an; i++)
    {
        for(int j = 1; j <= bm; j++)
        {
            int sum = 0;
            for(int k = 1; k <= am; k++)
                sum += (A[i][k] * B[k][j]);
            cout << sum << ' ';
        }
        cout << '\n';
    }

}