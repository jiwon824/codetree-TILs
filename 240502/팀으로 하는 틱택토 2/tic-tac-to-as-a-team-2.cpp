#include <iostream>

using namespace std;
int board[3][3];

bool Check(int a, int b){
    //cout << a << " "<< b <<'\n';
    // 가로 확인
    for(int i=0; i<3; i++){
        bool isAnswer= true;
        for(int j=0; j<3; j++){
            if(board[i][j]==a || board[i][j]==b) continue;
            isAnswer= false;
        }

        // 가로가 전부 같은 줄이면 정답 아님
        if((board[i][0]==a && board[i][1]==a && board[i][2]==a)||
           (board[i][0]==b && board[i][1]==b && board[i][2]==b)) isAnswer = false;

        if(isAnswer) return true;
    }

    //cout << "가로 정답 아님\n";

    // 가로가 정답이 아니니까 다른 경우도 봐야 함
    // 세로 확인
    for(int i=0; i<3; i++){
        bool isAnswer = true;
        for(int j=0; j<3; j++){
            if(board[j][i]==a || board[j][i]==b) continue;
            isAnswer= false;
        }
        // 세로가 전부 같은 줄이면 정답 아님
        if((board[0][i]==a && board[1][i]==a && board[2][i]==a)||
           (board[0][i]==b && board[1][i]==b && board[2][i]==b)) isAnswer = false;

        if(isAnswer) return true;
    }
    
    //cout << "세로 정답 아님\n";

    // \대각선 확인
    if((board[0][0] == a || board[0][0] == b) &&
       (board[1][1] == a || board[1][1] == b) &&
       (board[2][2] == a || board[2][2] == b)){
        if(!(board[0][0] == a && board[1][1] == a && board[2][2] == a) &&
           !(board[0][0] == b && board[1][1] == b && board[2][2] == b)) return true;
       }
    
    //cout << " \\대각선 정답 아님\n";
    
    //  /대각선 확인
    if((board[0][2] == a || board[0][2] == b) &&
       (board[1][1] == a || board[1][1] == b) &&
       (board[2][0] == a || board[2][0] == b)) {
        if(!(board[0][2] == a && board[1][1] == a && board[2][0] == a) &&
           !(board[0][2] == b && board[1][1] == b && board[2][0] == b)) return true;
       }
    
    //cout << " /대각선 정답 아님\n";
    
    // 위에 체크할 때 한 번도 빠져나가지 못했으면 답이 없음
    return false;
}

int main() {
    for(int i=0; i<3; i++){
        string num;
        cin >> num;
        board[i][0]=num[0]-'0';
        board[i][1]=num[1]-'0';
        board[i][2]=num[2]-'0';

        //cout << board[i][0]<< " " << board[i][1]<< " " << board[i][2]<< '\n';
    }
    
    int answer =0;
    for(int i=1; i<=9; i++){
        for(int j=i+1; j<=9; j++){
            if(i==j) continue; // 팀으로 이겨야 함
            
            // 가로 세로 우대각 좌대각 확인
            if(Check(i, j)) answer++;
            //cout << i << " " << j << " " << Check(i, j)<<'\n';
        }
    }
    cout << answer;
    return 0;
}