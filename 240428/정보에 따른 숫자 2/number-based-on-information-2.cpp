#include <iostream>

using namespace std;


char arr[1001];
// x = a부터 x = b까지의 위치 중 특별한 위치의 수를 구하는 프로그램
    // 어떤 위치 k에서 가장 가까이에 있는 알파벳 S까지의 거리 d1
    // k에서 가장 가까이에 있는 알파벳 N까지의 거리 d2
    // d1<=d2인 경우 x = k는 특별한 위치
int main() {
    int t, a, b;
    cin >> t >> a >> b;
    for(int i=0; i<t; i++){
        char c;
        int x;
        cin >> c >> x;
        arr[x]=c;
    }
    
    int answer =0;
    for(int i=a; i<=b; i++){
        int dist_s=1000, dist_n=1000;
        // 특정 위치 i에서 가장 가까이 있는 s의 위치
        for(int j=0; j<=b; j++){
            if(arr[j]=='S'){
                if(abs(i-j)<=dist_s)dist_s = abs(i-j);
            }
        }
        // 특정 위치 i에서 가장 가까이 있는 n의 위치
        for(int j=0; j<=b; j++){
            if(arr[j]=='N'){
                if(abs(i-j)<dist_n)dist_n = abs(i-j);
            }
        }

        if(dist_s<=dist_n) answer++;
    }

    cout << answer;

    return 0;
}