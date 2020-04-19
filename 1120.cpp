// BOJ - 1120

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	int a_len = a.length();
	int b_len = b.length();
	int ans=987654321;
	for(int i=0; i<b_len-a_len+1; i++)
	{
		int temp = 0;
		for(int j=0; j<a_len; j++)
			if(a[j]!=b[i+j]) temp++;
		ans = min(ans,temp);
	}
	printf("%d",ans);
}
