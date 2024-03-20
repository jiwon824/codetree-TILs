#include <iostream>

using namespace std;
int Solution(int n){
    int answer = 0;
    for(int i=1;i<=n;i++){
        answer += i;
    }
    return answer/10;
}
int main() {
    int n;
    cin >> n;
    int answer=Solution(n);
    cout << answer;
    return 0;
}