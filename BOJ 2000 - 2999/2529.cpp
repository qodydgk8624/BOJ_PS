// BOJ - 2529

/*
	prev_permutation , next_permutation application
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;

int chk(vector<int>& v)
{
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='<' && v[i]>v[i+1]) return 0;
		if(s[i]=='>' && v[i]<v[i+1]) return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int k;
	cin >> k;
	for(int i=0; i<k; i++)
	{
		char _t;
		cin >> _t;
		s += _t;
	}
	vector<int> maxV;
	vector<int> minV;
	for(int i=9; i>9-k-1; i--) maxV.push_back(i);
	for(int i=0; i<k+1; i++) minV.push_back(i);
	while(1)
	{
		if(chk(maxV)) break;
		prev_permutation(maxV.begin(),maxV.end());
	}
	while(1)
	{
		if(chk(minV)) break;
		next_permutation(minV.begin(),minV.end());
	}
	for(auto& i: maxV) cout<<i;
	cout<<'\n';
	for(auto& i: minV) cout<<i;
	cout<<'\n';
	
	
}
