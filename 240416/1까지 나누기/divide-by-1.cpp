#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int answer=0;
    for(int i=1;;i++){
        if(n<=1) break;
        n /= i;
        answer++;
    }
    cout << answer;
    
    return 0;
}