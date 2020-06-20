// BOJ - 1764 듣보잡

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	vector<string> result;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int j=0; j<m; j++)
		cin >> b[j];	
	sort(a.begin(),a.end());
	
	for(int i=0; i<m; i++)
		if(binary_search(a.begin(),a.end(),b[i]))
			result.push_back(b[i]);
	
	sort(result.begin(),result.end());
	cout << result.size() << endl;
	
	for(int i=0; i<result.size(); i++)
		cout << result[i] << "\n";
 } 