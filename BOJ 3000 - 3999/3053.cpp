// BOJ-3053 택시 기하학

#include <iostream>
#include <cmath>

// 이 문제에서는 M_PI 를 처음봤다!
 
using namespace std;

int main()
{
	double r;
	cin >> r;
	printf("%.6lf\n",r*r*M_PI);
	printf("%.6lf\n",r*r*2);
} 