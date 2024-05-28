#include <iostream>

using namespace std;

int arr[21][21];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int answer =0;
    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=n-3;j++){
            // (i, j)에서 3*3구역 탐색
            int coin=0;
            for(int k=i; k<i+3; k++){
                for(int l=j; l<j+3; l++){
                    if(k>=n || l>=n) continue;
                    coin += arr[k][l];
                }
            }
            if(answer<coin) answer=coin;
        }
    }
    cout << answer<<'\n';
    return 0;
}