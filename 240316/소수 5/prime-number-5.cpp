#include <iostream>

using namespace std;
int main() {
    int a, b;
    cin >> a>> b;
    int answer=0;
    for (int i=a;i<=b;i++){
        bool isPrime=true;
        for(int j=2;j<i/2;j++){
            if (i%j==0) isPrime=false;
        }
        if(isPrime) answer++;
    }
    cout << answer;
    return 0;
}