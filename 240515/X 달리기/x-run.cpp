#include <iostream>

using namespace std;

/*
[25m를 가는 경우]
시간 속도 거리
1    1   1
2    2   3
3    3   6
4    4   10
5    5   15
6    4   19
7    3   22
8    2   24
9    1   25
*/
int main() {
    int x; // 1<=x<=10,000
    cin >> x;

    int dist =1, time=1, speed=1;
    //cout <<"time\tspeed\tdist\n";

    while(dist<x){
        //cout << time << "\t" << speed << "\t" << dist << '\n';
        // 가속했을 때 남은 거리x-dist-(speed+1)가
        // 가속한 후 감속만 했을 때 이동거리 (speed+1)*speed/2 보다 크면 가속
        if(x-dist-(speed+1) >= (speed+1)*speed/2){
            speed++;
        }
        // 현재 속도를 유지했을 때 남은 거리(x-dist-speed)가
        // 앞으로 감속만 했을 때의 이동거리(speed*(speed-1)/2)보다 작으면 유지 못함(감속)
        else if(x-dist-speed < speed*(speed-1)/2){
            speed--;
        }
        time++;
        dist+=speed;
    }
    cout << time <<'\n';
    return 0;
}