#include <iostream>

using namespace std;
int main() {
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1, d1, m2, d2;
    cin >>m1>>d1>>m2>>d2;
    
    // 윤년이 아닌 해라고 가정
    int month=m1, day=d1, answer=1;
    while(true){
        if(month==m2 && day==d2) break;
        answer++;
        day++;
        if(day>num_of_days[month]){
            day=1;
            month++;
        }
    }
    cout << answer;
    return 0;
}