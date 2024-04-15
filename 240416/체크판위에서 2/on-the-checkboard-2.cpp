#include <iostream>

using namespace std;
char arr[16][16];
int main() {
    int r, c;
    cin >> r >> c;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cin >> arr[i][j];
        }
    }

    int answer=0;
    for(int i=1;i<r;i++){
        for(int j=1; j<c; j++){
            for(int k=i+1; k<r-1; k++){// 아래로 한 칸
                for(int l=j+1; l<c-1; l++){ // 오른쪽으로 한 칸
                    if(arr[0][0]!=arr[i][j] && arr[i][j]!=arr[k][l] && arr[k][l]!=arr[r-1][c-1]) answer++;
                }
            }
        }
    }
    cout << answer;

    return 0;
}