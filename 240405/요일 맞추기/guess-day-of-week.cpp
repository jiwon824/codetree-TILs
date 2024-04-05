#include <iostream>
#include <algorithm>
using namespace std;
// 2011년 m1월 d1일이 **월요일** 이었다면, 2011년 m2월 d2은 어떤 요일인지를 구하는 프로그램
int main() {
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day_of_week[7]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int ans =0;
    
    int num1 = num_of_days[m1]+d1;
    int num2 = num_of_days[m2]+d2;
    //cout << num1 << " " << num2 <<'\n';
    int diff = num2-num1;
    if (diff<0) diff = diff+7;
    ans=(ans+diff)%7;

    cout << day_of_week[ans];
    return 0;
}