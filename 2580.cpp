// BOJ - 2580 스도쿠

#include <iostream>
#include <vector>
#define MAXN 9

using namespace std;

int map[MAXN][MAXN] = {0, };

struct point {
    int x, y;
};

point make_point(int x, int y)
{
    point p;
    p.x = x; p.y = y;
    return p;
}

vector<int> get_availableNum(int x, int y)
{
    int num[10] = {0, };
    int nx = x / 3 * 3, ny = y / 3 * 3;

    for(int dy = 0; dy < MAXN; dy++) // 가로
        num[map[x][dy]]++;

    for(int dx = 0; dx < MAXN; dx++) // 세로
        num[map[dx][y]]++;

    for(int dx = nx; dx < nx + 3; dx++) // 3x3
        for(int dy = ny; dy < ny + 3; dy++)
            num[map[dx][dy]]++;

    vector<int> available;

    for(int i = 1; i <= 9; i++)
        if(num[i] == 0)
            available.push_back(i);

    return available;
    
}
vector<point> zero;

void dfs(int cnt)
{
    if(zero.size() == 0) return; // 0이 아예 없는 경우

    if(cnt == zero.size()) // 끝날 경우
    {
        for(int i = 0; i < MAXN; i++)
        {
            for(int j = 0; j < MAXN; j++)
                cout << map[i][j] << ' ';
            cout << '\n';
        }

        exit(0);

    }
        
    int x = zero[cnt].x, y = zero[cnt].y;
    vector<int> available = get_availableNum(x, y);

    if(available.size() == 0) return; // 실패!

    for(int i = 0; i < available.size(); i++)
    {
        int number = available[i];
        map[x][y] = number;
        dfs(cnt + 1);
        map[x][y] = 0;
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
        {
            cin >> map[i][j];
            if(!map[i][j]) zero.push_back(make_point(i, j));
        }

    dfs(0);

}