// BOJ - 2261 가장 가까운 두 점 찾기

#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#define MAXN 100000

using namespace std;

struct Point
{
    int x, y;
    Point()
    {

    }

    Point(int x, int y) : x(x), y(y)
    {

    }
    bool operator<(const Point b) const
    {
        if(y == b.y) return x < b.x;
        else return y < b.y;
    }
    bool operator>(const Point b) const
    {
        if(y == b.y) return x > b.x;
        else return y > b.y;
    }
};

bool cmp(Point a, Point b)
{
    return a.x < b.x;
}

int dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    Point a[n];

    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmp);

    set<Point> candidate = {a[0], a[1]};

    int ans = dist(a[0], a[1]); int start = 0;

    for(int i = 2; i < n; i++)
    {
        Point cur = a[i];
        while(start < i)
        {
            Point p = a[start];
            if((cur.x - p.x) * (cur.x - p.x) > ans)
            {
                candidate.erase(p); start++;
            }
            else break;
        }

        int d = (int) sqrt((double) ans) + 1;
        Point lp = Point(-MAXN, cur.y - d);
        Point up = Point(MAXN, cur.y + d);

        auto l = candidate.lower_bound(lp);
        auto u = candidate.upper_bound(up);

        for(auto it = l; it != u; it++)
        {
            int d = dist(cur, *it);
            if(d < ans) ans = d;
        }
        candidate.insert(cur);
    }
    
    cout << ans;

}