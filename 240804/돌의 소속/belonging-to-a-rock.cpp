#include <iostream>
using namespace std;

int arr[100001];
int prefix_sum[4][100001]; // 각 돌은 그룹 1, 2, 3 중 하나에 무조건 속합니다.

int main() {
    // input
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
        prefix_sum[arr[i]][i]++;
    }
    
    // prefix 채우기
    for(int i=1; i<=3; ++i){
        for(int j=1; j<=n; ++j){
            prefix_sum[i][j]+=prefix_sum[i][j-1];
        }
    }

    // 범위에 있는 1, 2, 3번 돌 개수 출력
    while(q--){
        int s, e;
        cin >> s >> e;
        int numOf1=prefix_sum[1][e]-prefix_sum[1][s-1];
        int numOf2=prefix_sum[2][e]-prefix_sum[2][s-1];
        int numOf3=prefix_sum[3][e]-prefix_sum[3][s-1];
        cout << numOf1 << " " << numOf2 << " " << numOf3 <<'\n';
    }

    return 0;
}