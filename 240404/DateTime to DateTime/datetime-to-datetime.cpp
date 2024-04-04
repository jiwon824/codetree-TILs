#include <iostream>

using namespace std;
int main() {
    int a, b, c;
    cin >>a>>b>>c;
    //11일 11시 11분에서 시작하여 a일 b시 c분까지 몇 분이 걸리는지
    int day=11, time=11, min=11, answer=0;
    while (true){
        // 단, a일 b시 c분이 11일 11시 11분보다 더 앞서다면(=작다면) -1을 출력
        if(a<11){
            cout << "-1";
            break;
        }
        if (a==11 && b<11){
            cout << "-1";
            break;
        }
        if (a==11 && b==11 && c<11){
            cout << "-1";
            break;
        }

        
        if(day==a && time==b && min==c) break;
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
    
    if (a==11 && b==11 && c==11) cout << "0";
    else if(answer!=0) cout << answer;
    
    return 0;
}