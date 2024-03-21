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
    cin >> y >> m >> d;
    // 2월은 윤년 판단
    // 4, 6, 9, 11월은 30일까지
    // 1, 3, 5, 7, 8, 10, 12월은 31일까지
    if (m==2){
        if(d>=30) cout << "-1";
        else if(d==29){
            if(IsLeapYear(y)) PrintSeason(m);
            else cout <<"-1";
        }
        else PrintSeason(m);
    }
    else if(m==4 || m==6 || m==9 || m==11){
        if(d==31) cout << "-1";
        else PrintSeason(m);
    }
    else PrintSeason(m);

    return 0;
}