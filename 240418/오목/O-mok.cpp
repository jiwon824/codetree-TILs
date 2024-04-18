#include <iostream>
#define MAX_RANGE 19
using namespace std;

int map[19][19];
int winner=0, winning_r=0, winning_c=0;

// 가로  - [i][j] [i][j+1] [i][j+2] [i][j+3] [i][j+4]
// 세로  | [j][i] [j+1][i] [j+2][i] [j+3][i] [j+4][i]
// 대각선 \ [i][j] [i+1][j+1] [i+2][j+2] [i+3][j+3] [i+4][j+4]
// 대각선 / [i][j] [i-1][j-1] [i-2][j-2] [i-3][j-3] [i-4][j-4]
void WinCheck(int i, int j){
    // '/' 검사는 j+4가 MAX_RANGE보다 큰지 검사할 필요 없음
        // [04, 13, 22, 31, 40]
    if(i>=4 && j>=4){
        if (map[i-4][j]!=0 && map[i-3][j-1]!=0 && map[i-2][j-2]!=0 && map[i-1][j-3]!=0 && map[i][j-4]!=0){
            if(map[i-4][j]==1 && map[i-3][j-1]==1 && map[i-2][j-2]==1 && map[i-1][j-3]==1 && map[i][j-4]==1){
                winner =1;
                winning_r =i-2;
                winning_c =j-2;
            }
            else if(map[i-4][j]==2 && map[i-3][j-1]==2 && map[i-2][j-2]==2 && map[i-1][j-3]==2 && map[i][j-4]==2){
                winner =2;
                winning_r =i-2;
                winning_c =j-2;
            }
        }
    }

    // 이 밑에 애들은 j+4>MAX_RANGE면 배열 밖 범위를 검사하게 됨
    if(j+4>MAX_RANGE) return;
    if(map[i][j]!=0 && map[i][j+1]!=0 && map[i][j+2]!=0 && map[i][j+3]!=0 && map[i][j+4]!=0){
        if(map[i][j]==1 && map[i][j+1]==1 && map[i][j+2]==1 && map[i][j+3]==1 && map[i][j+4]==1){
            winner =1;
            winning_r =i;
            winning_c =j+2;
        }
        else if(map[i][j]==2 && map[i][j+1]==2 && map[i][j+2]==2 && map[i][j+3]==2 && map[i][j+4]==2){
            winner =2;
            winning_r =i;
            winning_c =j+2;
        }
        // 여기서 winning_r, winning_c 갱신하면 21222이렇게 0이 아닌 수가 이어져도 갱신됨
    }
    if(map[j][i]!=0 && map[j+1][i]!=0 && map[j+2][i]!=0 && map[j+3][i]!=0 && map[j+4][i]!=0){
        if(map[j][i]==1 && map[j+1][i]==1 && map[j+2][i]==1 && map[j+3][i]==1 && map[j+4][i]==1){
            winner =1;
            winning_r =j+2;
            winning_c =i;
        }
        else if(map[j][i]==2 && map[j+1][i]==2 && map[j+2][i]==2 && map[j+3][i]==2 && map[j+4][i]==2){
            winner =2;
            winning_r =j+2;
            winning_c =i;
        }
    }

    // '\' 검사 예시
        // [00 11 22 33 44] 
    if(map[i][j]!=0 && map[i+1][j+1]!=0 && map[i+2][j+2]!=0 && map[i+3][j+3]!=0 && map[i+4][j+4]!=0){
        if(map[i][j]==1 && map[i+1][j+1]==1 && map[i+2][j+2]==1 && map[i+3][j+3]==1 && map[i+4][j+4]==1){
            winner =1;
            winning_r =i+2;
            winning_c =j+2;
        }
        else if(map[i][j]==2 && map[i+1][j+1]==2 && map[i+2][j+2]==2 && map[i+3][j+3]==2 && map[i+4][j+4]==2){
            winner =2;
            winning_r =i+2;
            winning_c =j+2;
        }
    }
}

// 검은색 바둑알(1)이 이겼는지, 흰색 바둑알(2)이 이겼는지 또는 아직 승부가 결정되지 않았는지를 판단하는 프로그램
int main() {
    // 입력
    for(int i=0;i<MAX_RANGE;i++){
        for(int j=0; j<MAX_RANGE; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<MAX_RANGE; i++){
        for(int j =0; j<MAX_RANGE; j++){
            WinCheck(i, j);
            //cout << winning_r << " " << winning_c <<'\n';
        }
    }

    cout << winner << '\n';
    if(winner>0) cout << winning_r+1 << " " << winning_c+1;
    return 0;
}