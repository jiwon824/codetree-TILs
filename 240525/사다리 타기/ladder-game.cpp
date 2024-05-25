#include <iostream>
#include <vector>
#include <cstring> // memset()

using namespace std;

int n=0, m=0, answer=100;
int board[16][12];

vector<pair<int, int>> lines;
vector<pair<int, int>> lines_to_remove;
vector<int> origin_result;

// result의 값을 변환하거나 하지 않아서 참조로 넘기지 않아도 됨
// origin_result랑 같으면 true 다르면 false
bool Possible(vector<int> result){
    return origin_result==result;
}

void Make_Board(){
    //board초기화
    memset(board, 0, sizeof(board));

    // line을 그리기
    for(int i=0; i<(int)lines.size(); i++){
        board[lines[i].first][lines[i].second]=1;
        board[lines[i].first][lines[i].second+1]=2;
    }
    // lines_to_remove에 들어있는 선 지우기
    for(int i=0; i<(int)lines_to_remove.size(); i++){
        board[lines_to_remove[i].first][lines_to_remove[i].second]=0;  
        board[lines_to_remove[i].first][lines_to_remove[i].second+1]=0;  
    }

}

vector<int> Play(){
    //board 그리기
    Make_Board();

    vector<int> result(n); //n개의 공간 확보

    // player별로 이동시키기
    for(int player=0; player<n; player++){
        int pos_x =0, pos_y=player;

        while(pos_x<16){
            // 1이면 오른쪽 왼쪽 확인해서 1인 곳으로 이동하고 아래로 한 칸 내려가기
            // 0이면 가로줄이 없다는 뜻이므로 그냥 아래로 내려가기
            if(board[pos_x][pos_y]==1){
                //오른쪽 이동
                if(pos_y+1<n && board[pos_x][pos_y+1]==2){
                    pos_y++;
                }
            }
            else if(board[pos_x][pos_y]==2){
                // 왼쪽 이동
                if(pos_y-1>=0 && board[pos_x][pos_y-1]==1){
                    pos_y--;
                }
            }
            pos_x++;
        }
        result[pos_y]=player;
    }
    return result;
}

void FindMinLineSegments(int idx_line){
    // 종료 조건
    if(idx_line==m){
        vector<int> v = Play();
        // [갱신]처음과 결과가 같은데, 저장된 것보다 더 적은 선분을 이용했을 경우
        if(Possible(v)){
            //cout << "possible\n";
            //for(int i=0; i<m; i++){
            //    for(int j=0; j<n; j++){
            //        cout << board[i][j]<< " ";
            //    }
            //    cout << '\n';
            //}
            int num_of_line = m-(int)lines_to_remove.size();
            if (num_of_line<answer) answer = num_of_line;
        }
        return;
    }
    // 재귀 호출
    // m개의 선 중 lines[idx_line]을 지우는 경우
    lines_to_remove.push_back(lines[idx_line]);
    FindMinLineSegments(idx_line+1);

    // m개의 선 중 lines[idx_line]을 지우지 않는 경우
    lines_to_remove.pop_back();
    FindMinLineSegments(idx_line+1);
}

int main() {
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        // 문제는 배열이 1부터 시작하기 때문에 1을 뺀 값을 적용.
        a-=1;
        b-=1;
        lines.push_back({b, a});
    }

    origin_result = Play();
    FindMinLineSegments(0);
    cout << answer;
    return 0;
}