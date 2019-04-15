// BOJ - 11054
//				11054 - ���� �� ������� �κ� ����

// �� ������ LIS�� LDS(ReversedLIS)�� ���ϴ� ������ ������ ���� LIS , ������ LDS ��
// ���ؼ� ���� ���߿� ���� ū ������ 1�� ���� �ȴ�.

// 1 �� �� ������ ���ϴ� ������ 2�� ��ġ�� �����̴�. 

#include <iostream>

using namespace std;

int d_lis[1001],n;
int d_lds[1001];
int ori_arr[1001];

int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int maxv=0;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> ori_arr[i];
	//LIS
	for(int i=1; i<=n; i++)
	{
		d_lis[i]=1;
		for(int j=1; j<i; j++)
			if(ori_arr[j]<ori_arr[i] && d_lis[i]<d_lis[j]+1)
				d_lis[i]++;
	}
	// ReverseLIS 
	for(int i=n; i>=1; i--)
	{
		d_lds[i]=1;
		for(int j=n; j>=i; j--)
			if(ori_arr[j]<ori_arr[i] && d_lds[i]<d_lds[j]+1)
				d_lds[i]++;
	}
    
    for(int i=1; i<=n; i++)
        maxv=max(maxv,d_lis[i]+d_lds[i]);
			
	cout << maxv-1;
	
} 
