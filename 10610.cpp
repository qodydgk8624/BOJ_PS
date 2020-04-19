// BOJ - 10610

// �� ������ ��� ���� ���̽����� Ǫ�°�..

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> n;
	bool have_zero = false;
	int sum = 0;
	for(int i=0; i<s.length(); i++)
	{
		sum+=s[i];
		n.push_back(s[i]-'0');
	}
	sort(n.begin(),n.end(), greater<int>());
	if(n[n.size()-1]==0 && sum%3==0)
	{
		for(int i=0; i<n.size(); i++)
			printf("%d",n[i]);
	}
	else
		puts("-1");
} 
