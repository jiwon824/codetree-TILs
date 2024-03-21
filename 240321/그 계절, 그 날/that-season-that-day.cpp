#include <iostream>

using namespace std;
void PrintSeason(int month){
    if(month>=3 && month<=5) cout << "Spring";
    else if(month>=6 && month<=8) cout << "Summer";
    else if(month>=9 && month<=11) cout << "Fall";
    else cout << "Winter";
}
bool IsLeapYear(int year){
    if(year%4==0 && year%100==0&&year%400==0) return true;
    if(year%4==0 && year%100==0) return false;
    if(year%4==0) return true;
    return false;
}
int main() {
    int y, m, d;
    cin >>y>>m>>d;
    // 홀수 달은 31일이 존재 짝수 달은 31일이 없음
    if(m%2==0){
        if(m==2 && d==29){
            if(IsLeapYear(y)) PrintSeason(m);
            else cout <<"-1";
        }
        else if(d==31) cout << "-1";
        else PrintSeason(m);
    }
    else PrintSeason(m);

    return 0;
}