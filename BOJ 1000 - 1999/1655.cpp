// BOJ - 1655 가운데를 말해요

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    while(n--)
    {
        int m; cin >> m;

        if(maxHeap.size() == minHeap.size()) maxHeap.push(m);
        else minHeap.push(m);

        if(maxHeap.size() != 0 && minHeap.size() != 0 && maxHeap.top() > minHeap.top())
        {
            int max = maxHeap.top(), min = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(min), minHeap.push(max);
        }

        cout << maxHeap.top() << '\n';
    }
}