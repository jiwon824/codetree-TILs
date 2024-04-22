#include <iostream>

using namespace std;

int main() {
    int n;
    cin >>n;
    int a, b, c;
    cin >> a >> b >> c;

    // 1부터 n까지 중복해서 3자리 뽑기
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(abs(i-a)<=2 || abs(j-b)<=2 || abs(k-c)<=2) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}