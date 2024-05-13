#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a=0, b=0;
    int answer=0;
    for(int i=0;i<n; i++){
        char person;
        int score;
        cin >>person >> score;
        int na=a, nb=b;
        if(person =='A'){
            na+=score;
        }
        else{
            nb+=score;
        }
        // 변동이 없을 경우 아무것도 하지 않음
        if((a>b && na>nb) || (b>a && nb>na) || (a==b && na==nb)) {
            // do nothing
        }
        else{
            answer++;
        }
        a=na;
        b=nb;
    }
    cout << answer;
    return 0;
}