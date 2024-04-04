#include <iostream>

using namespace std;
int main() {
    int a, b, c;
    cin >>a>>b>>c;
    //11일 11시 11분에서 시작하여 a일 b시 c분까지 몇 분이 걸리는지
    int day=11, time=11, min=11, answer=0;
    while (true){
        if(day==a && time ==b && min ==c) break;
        min++;
        answer++;

        if(min>59) {
            time++;
            min=0;
        }
        if(time>23){
            day++;
            time=0;
        }
    }
    cout << answer;
    return 0;
}