// BOJ - 1068

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct
{
	int parent;
	vector<int> child;
} node;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	node data[n];
	int visited[n]={0};
	for(int i=0; i<n; i++)
	{
		int _t;
		cin >> _t;
		data[i].parent=_t;
		if(_t!=-1)
		{
			data[_t].child.push_back(i);
		}
	}
	int remove;
	cin >> remove;
	queue<int> q;
	q.push(remove);
	while(!q.empty())
	{
		int _t = q.front();
		visited[_t]=1;
		q.pop();
		for(int i=0; i<data[_t].child.size(); i++)
			q.push(data[_t].child[i]);
	}
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		int childn = data[i].child.size();
		for(int j=0; j<data[i].child.size(); j++)
		{
			if(visited[data[i].child[j]] == 1)
				childn--;
		}
		if(!visited[i] && !childn)
			ans++;
	}
		
	cout << ans;
}
