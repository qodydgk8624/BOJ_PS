// BOJ - 5543 상근날드

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A[3]={0}, B[2]={0};
	for(int i=0; i<3; i++)
		cin >> A[i];
	for(int i=0; i<2; i++)
		cin >> B[i];
	sort(A, A+3);
	sort(B, B+2);
	cout << A[0]+B[0]-50;
}
