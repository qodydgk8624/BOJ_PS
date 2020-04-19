// BOJ - 13323

#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
	int A[n],diff[n];
	priority_queue<int> pq;
	ll sum = 0;
	for(int i=0; i<n; i++) cin >> A[i]; 
	for(int i=0; i<n; i++)
	{
		int t1 = A[i]-i;
		if(!pq.empty())
		{
			if(pq.top() > t1)
			{
				sum += pq.top()-t1;
				pq.pop(); pq.push(t1);
			}
		}
		pq.push(t1);
		diff[i] = pq.top();
	}
	for(int i=n-2; i>=0; i--) if(diff[i] > diff[i+1]) diff[i] = diff[i+1];
	//for(int i=0; i<n; i++) cout << diff[i] + i << '\n';
	cout << sum << '\n';
}
