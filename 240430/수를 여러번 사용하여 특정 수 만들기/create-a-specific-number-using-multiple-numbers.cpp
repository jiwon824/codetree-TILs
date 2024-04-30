#include <iostream>

using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // A와 B를 0번 이상 더해서 만들 수 있는 C 이하인 수 중에서 가장 큰 값
    int answer =0;
    for(int i=0; i<c/a;i++){
        for(int j=0; j<1000; j++){
            int num = a*i+b*j;
            if(num>c) break;
            if(answer<num) answer=num;
        }
    }
    cout << answer;
    return 0;
}