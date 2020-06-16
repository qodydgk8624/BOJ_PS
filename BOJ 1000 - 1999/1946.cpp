// BOJ - 1946

#include <iostream>
#include <algorithm>

using namespace std;

struct score {
	int f,s;
};
bool comp(score a,score b) {
	return a.f<b.f;
};
int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n,ans = 1;
		cin >> n;
		score s[n];
		for(int i=0; i<n; i++)
			cin >> s[i].f >> s[i].s;
		sort(s,s+n,comp);
		int cmpv = s[0].s;
		for(int i=1; i<n; i++)
		{
			if(s[i].s < cmpv)
			{
				cmpv = s[i].s;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}
