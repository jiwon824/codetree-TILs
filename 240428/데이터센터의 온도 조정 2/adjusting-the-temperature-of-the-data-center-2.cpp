#include <iostream>

using namespace std;
int temperature[1000][2];
int main() {
    // 장비의 개수 n과 온도에 따른 장비들의 작업량 c, g, h
    int n, c, g, h;
    cin >> n >> c >> g >> h;

    int min_temp=1000, max_temp=0;
    for(int i=0; i<n; i++){
        cin >> temperature[i][0] >> temperature[i][1];
        if(min_temp > temperature[i][0]) min_temp = temperature[i][0];
        if (max_temp<temperature[i][1]) max_temp = temperature[i][1];
    }

    int answer =0;
    for(int i=min_temp; i<=max_temp; i++){
        // 온도가 i일 때 각 장비의 작업속도
        int task=0;
        for(int j=0; j<n; j++){
            if(i < temperature[j][0]) task+=c;
            else if(temperature[j][1] < i) task+=h;
            else task += g;
        }
        if(answer<task) answer = task;
    }
    cout << answer;
    return 0;
}