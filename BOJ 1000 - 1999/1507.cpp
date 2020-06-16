// BOJ - 1507

// Floyd-Warshall Algorithm

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int dp[n+1][n+1]={0};
	int ori[n+1][n+1]={0};
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			int t;
			cin >> t;
			ori[i][j] = t;
			dp[i][j] = t;
		}
			
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if((i==k) | (j==k)) continue;
				if(dp[i][j]==dp[i][k]+dp[k][j])
					ori[i][j]=0;
				else if(dp[i][j]>dp[i][k]+dp[k][j])
					return !printf("-1");
			}
		}
	}
	int chk[n+1][n+1]={0};
	
	int sum=0;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(ori[i][j] != 0 & !chk[i][j])
			{
				sum+=ori[i][j];
				chk[i][j] = chk[j][i] = 1;
			}
		}
		
	printf("%d",sum);
}
