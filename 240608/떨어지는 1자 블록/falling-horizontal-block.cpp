#include <iostream>

using namespace std;

int n, m, k;
int board[101][101];

void Play(){
    // 1*m 크기의 블럭 밑으로 떨구기
    int xPos=0;
    for(int row=0; row<n; row++){
        bool isPass=true;
        for(int col=k; col<k+m; col++){
            if(board[row][col]==1) isPass=false;
        }
        if(isPass) xPos=row;
        else break;
    }

    // 블럭 설치
    for(int col=k; col<k+m; col++){
        board[xPos][col]=1;
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>board[i][j];
        }
    }
    k-=1;

    Play();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout <<'\n';
    }

    return 0;
}