#include <iostream>

using namespace std;

int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string  list_of_day_of_week[7]={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int ConvertDayOfWeekToInt(string s){
    for(int i=0; i<7; i++){
        if(list_of_day_of_week[i]==s) return i;
    }
}
// 2024년 m1월 d1일이 월요일 이었다면, 2024년 m2월 d2까지 A 요일은 몇 번 등장하는지 구하는 프로그램
// 2024년은 윤년이기 때문에 2월은 29일까지 있으며, (m2월 d2일)이 (m1월 d1일)보다 앞선 날짜로 주어지는 경우는 없다
int main() {
    int m1, d1, m2, d2;
    string day_of_week;
    cin >> m1 >> d1 >> m2 >> d2 >> day_of_week;
    
    int i_day_of_week = ConvertDayOfWeekToInt(day_of_week);
    //cout << i_day_of_week;

    // calculate_week는 무슨 요일인지 계산하는 변수. calculate_week와 i_day_of_week가 같으면 같은 요일이므로 answer++
    int answer=0, calculate_week=0;
    while(true){
        //cout << d1 <<'\n';
        if(m1==m2 && d1==d2) break;
        if(calculate_week == i_day_of_week) answer++;
        d1++;
        calculate_week++;
        if(calculate_week>6) calculate_week = 0;
        if(num_of_days[m1]<d1){
            d1=1;
            m1++;
        }
    }
    if(calculate_week == i_day_of_week) answer++;
    
    cout << answer;
    return 0;
}