#include <iostream>

using namespace std;

int main() {
    int x; // 1<=x<=10,000
    cin >> x;

    int dist =0;
    int velocity=1; // 1m/s로 시작
    int time=0;
    while (dist<x){
        dist+=velocity;
        time++;
        // 속력을 올려야 하는 구간
        if(dist < x/2){
            velocity++;
        }
        // 속력을 내려야 하는 구간
        else if(dist >= x/2 && velocity>1){
            velocity--;
        }
        // 유지해야 하는 구간
        else if(dist >= x/2 &&velocity==1){
            // do nothing
        }
    }
    cout << time <<'\n';
    return 0;
}