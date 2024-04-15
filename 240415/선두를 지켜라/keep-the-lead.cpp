#include <iostream>

using namespace std;

int a[1000001];
int b[1000001];

// 선두가 몇번이 바뀌는지 찾아 출력하는 프로그램
int main() {
    int n, m;
    cin >> n >> m;

    int aTime=1, bTime=1;
    // A가 어떤 속도로 몇 시간 동안 이동했는지
    for(int i=0;i<n;i++){
        int v, t;
        cin >> v >> t;
        while(t--){
            a[aTime]= a[aTime-1]+v;
            aTime++;
        }

    }
    // B가 어떤 속도로 몇 시간 동안 이동했는지
    for(int i=0;i<m;i++){
        int v, t;
        cin >> v >> t;
        while(t--){
            b[bTime]= b[bTime-1]+v;
            bTime++;
        }

    }

    int answer =0;
    for(int i=2; i<aTime;i++){
        if(a[i-1]<=b[i-1] && a[i]>b[i]) answer++;
        if(a[i-1]>=b[i-1] && a[i]<b[i]) answer++;
    }
    cout << answer;

    return 0;
}