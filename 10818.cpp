// BOJ - 10818 최소, 최대

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int d[n] = {0};
	for(int i = 0; i < n; i++)
		cin >> d[i];
		
	sort(d, d + n);
	
	cout << d[0] << " " << d[n - 1];
}
