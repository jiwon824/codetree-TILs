#include <iostream>
#define MAX_N 100000
using namespace std;

int num[MAX_N];
int lMax[MAX_N]; // i까지의 값 중 최대를 왼쪽에서부터 저장
int rMax[MAX_N]; // i까지의 값 중 최대를 오른쪽에서부터 저장

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    // left
    lMax[0]=num[0];
    for(int i=1; i<n; ++i){
        lMax[i] = max(lMax[i-1], num[i]);
    }

    // right
    rMax[n-1]=num[n-1];
    for(int i=n-2; i>=0; --i){
        rMax[i]=max(rMax[i+1], num[i]);
    }

    // answer
    int answer = 0;
    for(int i=2; i<n-2; ++i){
        answer=max(answer, lMax[i-2]+num[i]+rMax[i+2]);
    }
    cout << answer << '\n';
    return 0;
}