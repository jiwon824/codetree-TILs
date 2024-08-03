#include <iostream>
using namespace std;

int n, k;
int arr[501][501];
int prefix_sum[501][501];

int main() {
    // input
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> arr[i][j];
        }
    }

    // solution
    // prefix_sum 채우기
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            prefix_sum[i][j]=prefix_sum[i-1][j]
                            +prefix_sum[i][j-1]
                            -prefix_sum[i-1][j-1]
                            +arr[i][j];
        }
    }
    
    //격자를 벗어나지 않는 k * k 크기의 정사각형 중 사각형 내 숫자들의 합이 최대가 되는 경우의 합
    int answer = prefix_sum[k][k];
    for(int i=k; i<=n; ++i){
        for(int j=k; j<=n; ++j){
            int sum = prefix_sum[i][j]
                    - prefix_sum[i-k][j]
                    - prefix_sum[i][j-k]
                    + prefix_sum[i-k][j-k];
            answer = max(answer, sum);
        }
    }
    cout << answer <<'\n';
    return 0;
}