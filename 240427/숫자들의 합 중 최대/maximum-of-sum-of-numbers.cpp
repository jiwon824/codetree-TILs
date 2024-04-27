#include <iostream>

using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int answer =0;
    for(int i=x; i<=y; i++){
        int num = i;
        int sum =0;
        while(num){
            sum += num%10;
            num/=10;
        }
        if(answer<sum) answer=sum;
    }
    cout << answer;
    return 0;
}