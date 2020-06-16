// BOJ - 2864 5와 6의 차이

// 2018년 7월에 작성된 코드입니다.

// C++11 에서 stoi() 함수를 통해 String 클래스로 풀어버릴수 있지만
// Dev C++ 에서는 구동하지 않으므로 다른 사람의 코드를 참조했습니다. 

#include <iostream>
using namespace std;
int A, B;
//최대가 되려면 5가 모두 6이 되어야 한다

int maxSum(void)

{

        int newA = 0, newB = 0;

        int copy = A;

        int multiplier = 1;

        while (copy)

        {

                 int temp = copy % 10;

                 if (temp == 5)

                         temp = 6;

                 newA += temp * multiplier;

                 multiplier *= 10;

                 copy /= 10;

        }

        copy = B;

        multiplier = 1;

        while (copy)

        {

                 int temp = copy % 10;

                 if (temp == 5)

                         temp = 6;

                 newB += temp * multiplier;

                 multiplier *= 10;

                 copy /= 10;

        }

        return newA + newB;

}

 

//최소가 되려면 6이 모두 5가 되어야한다

int minSum(void)

{

        int newA = 0, newB = 0;

        int copy = A;

        int multiplier = 1;

        while (copy)

        {

                 int temp = copy % 10;

                 if (temp == 6)

                         temp = 5;

                 newA += temp * multiplier;

                 multiplier *= 10;

                 copy /= 10;

        }

        copy = B;

        multiplier = 1;

        while (copy)

        {

                 int temp = copy % 10;

                 if (temp == 6)

                         temp = 5;

                 newB += temp * multiplier;

                 multiplier *= 10;

                 copy /= 10;

        }

        return newA + newB;

}

 

int main(void)

{

        cin >> A >> B;

 

        cout << minSum() << " " << maxSum() << endl;

        return 0;

}
