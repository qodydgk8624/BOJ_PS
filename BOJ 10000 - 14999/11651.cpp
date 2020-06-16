// BOJ - 11651 좌표 정렬하기 2

#include <iostream>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
    bool operator<(const point b)
    {
        if(y == b.y) return x < b.x;
        return y < b.y;
    }
    bool operator>(const point b)
    {
        if(y == b.y) return x > b.x;
        return y > b.y;
    }

};

int main()
{
    int n; cin >> n;
    point p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    
    sort(p, p + n);

    for(int i = 0; i < n; i++)
        cout << p[i].x << ' ' << p[i].y << '\n';
}