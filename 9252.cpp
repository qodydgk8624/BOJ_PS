// BOJ - 9252

#include <iostream>
#include <string>

int dp[1001][1001]={0};

using namespace std;

string a,b;

int max(int a,int b)
{
	return a>b?a:b;
}
int f(int i,int j)
{
	if(!dp[i][j]) return 0;
	a[i]==b[j]?f(i-1,j-1),putchar(a[i]):dp[i-1][j]>dp[i][j-1]?f(i-1,j):f(i,j-1);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	a.insert(a.begin(),0);
	b.insert(b.begin(),0);
	for(int i=1; i<=a.size(); i++)
		for(int j=1; j<=b.size(); j++)
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(a[i]==b[j]));
			
	printf("%d\n",dp[a.size()-1][b.size()-1]);
	
	f(a.size()-1,b.size()-1);
	
	/*
	puts("");
	for(int i=1; i<a.size(); puts(""),i++)
		for(int j=1; j<b.size(); j++)
			printf("%d ",dp[i][j]);
	*/
	
	
}
