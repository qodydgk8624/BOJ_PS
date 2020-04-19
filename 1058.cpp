// BOJ - 1058

#include <iostream>
#include <string>

using namespace std;

#define INF 987654321

int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cost[n][n]={0};
	for(int i=0; i<n; i++)
	{
		string t;
		cin >> t;
		for(int j=0; j<t.size(); j++)
		{
			if(i==j) cost[i][j]=0;
			else cost[i][j] = (t[j]=='Y'?1:INF);
		}
	}
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
			{
				if(j==k | i==k | i==j) continue;
				else if(cost[j][k]>cost[j][i]+cost[i][k])
					cost[j][k]=cost[j][i]+cost[i][k];
					
			}
			
	int ans=0;
	
	for(int i=0; i<n; i++)
	{
		int t = 0;
		for(int j=0; j<n; j++)
		{
			if(i==j) continue;
			else if(cost[i][j]<3)
				t++;
		}
		ans = max(ans,t);
	}
	printf("%d",ans);
}
