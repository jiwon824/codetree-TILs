#include <iostream>

using namespace std;

// (-1, -1) (-1, 0) (-1, 1)
// ( 0, -1) ( 0, 0) ( 0, 1)
// ( 1, -1) ( 1, 0) ( 1, 1)
// 좌 좌상 상 우상 우 우하 하 좌하
enum Dir{
    DIR_LEFT,
    DIR_LEFT_UP,
    DIR_UP,
    DIR_RIGHT_UP,
    DIR_RIGHT,
    DIR_RIGHT_DOWN,
    DIR_DOWN,
    DIR_LEFT_DOWN
};

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
int arr[201][201];

bool InRange(pair<int, int> block){
    if(block.first < 0 || block.first > n ||
       block.second < 0 || block.second > m) return false;
    return true;
}

int Cnt_Max_IBlock(){
    int max_sum =0;

    // arr[i][j]를 기준으로 L블록 배치
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 회전시키기
            // k = {0, 2}
            for(int k=0; k<4; k+=2){
                pair<int, int> block1 = {i+dx[0+k], j+dy[0+k]};
                pair<int, int> block2 = {i, j};
                pair<int, int> block3 = {i+dx[4+k], j+dy[4+k]};
                if(InRange(block1) && InRange(block2) && InRange(block3)){
                    int sum = arr[block1.first][block1.second] +
                              arr[block2.first][block2.second] +
                              arr[block3.first][block3.second];
                    if (max_sum<sum) max_sum = sum;
                }

            } // k

        } // j
    } // i

    return max_sum;
}

int Cnt_Max_LBlock(){
    int max_sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            for(int k=0; k<8; k+=2){
                pair<int, int> block1 = {i+dx[(0+k)%8], j+dy[(0+k)%8]};
                pair<int, int> block2 = {i+dx[(7+k)%8], j+dy[(7+k)%8]};
                pair<int, int> block3 = {i+dx[(6+k)%8], j+dy[(6+k)%8]};
                if(InRange(block1) && InRange(block2) && InRange(block3)){
                    int sum = arr[block1.first][block1.second] +
                              arr[block2.first][block2.second] +
                              arr[block3.first][block3.second];
                    if (max_sum<sum) max_sum = sum;
                }

            } // k

        }
    }
    return max_sum;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    cout << max(Cnt_Max_IBlock(), Cnt_Max_LBlock()) << '\n';
    return 0;
}