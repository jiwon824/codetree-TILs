#include <iostream>

using namespace std;

int arr[11][21];// [k][n]
int k, n;

int main() {
    cin >> k >> n;
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int answer =0;
    // i= {1, 2, 3, 4} j ={2, 3, 4}
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            //cout << "현재 비교 중인 개발자: " << i << "번 개발자 " << j <<"번 개발자\n";

            int win_cnt =0;
            for(int a=0; a<k; a++){
                int idx_i, idx_j;
                for(int b=0; b<n; b++){
                    if(arr[a][b]==i) idx_i = b;
                    if(arr[a][b]==j) idx_j = b;
                }
                if(idx_i<idx_j) win_cnt++;
                //cout << idx_i << " " << idx_j << " " << win_cnt << '\n';
            }
            if(win_cnt==k) answer++;
        }
    }

    cout << answer;
    return 0;
}