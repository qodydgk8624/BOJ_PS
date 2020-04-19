// BOJ - 5567

#include <iostream>
#include <queue>
#include <vector>

#define MAXN 500

using namespace std;

int n,m;
vector<int> map[MAXN+1];
int myfriend[MAXN+1];

queue<int> c;

int friendcalc()
{
	for(int i=0; i<map[1].size(); i++)
	{
		c.push(map[1][i]);
		myfriend[map[1][i]]=1;
	}
	while(!c.empty())
	{
		int _t = c.front();
		c.pop();
		for(int i=0; i<map[_t].size(); i++)
			myfriend[map[_t][i]]=1;
	}
	int ret=0;
	for(int i=2; i<=n; i++)
		if(myfriend[i])
			ret++;
	return ret;
}
int main()
{
	cin >> n >> m;
	for(int i=1; i<=m; i++)
	{
		int _1,_2;
		cin >> _1 >> _2;
		map[_1].push_back(_2);
		map[_2].push_back(_1);
	}
	
	cout << friendcalc();
}
