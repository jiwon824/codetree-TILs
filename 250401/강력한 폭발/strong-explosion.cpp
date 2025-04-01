#include <iostream>
#include <vector>
using namespace std;

int n, answer;
int grid[20][20];
vector<int> bombType;
vector<vector<pair<int,int>>> bombRange;


int check(){
    vector<vector<int>> result(n, vector<int> (n, 0));

    int idx=0;
    // 모든 영역을 돌면서 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 폭탄이 설치되어 있으면 범위를 터트림
            if(grid[i][j]==1){
                int type = bombType[idx++];
                for(pair<int,int> e: bombRange[type]){
                    int nx = i+e.first;
                    int ny = j+e.second;
                    
                    // 범위를 벗어난 접근
                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;

                    result[nx][ny] = 1;
                }
            }
        }
    }

    // 폭발 지역 갯수 세기
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(result[i][j]) cnt++;
        }
    }
    return cnt;
}

void backtracking(int cnt, int limit){
    // 종료 조건
    if(cnt>=limit){
        answer = max(answer, check());
        return;
    }

    // 재귀 호출(i는 폭탄의 종류를 의미)
    for(int i=1; i<=3; i++){
        bombType.push_back(i);
        backtracking(cnt+1, limit);
        bombType.pop_back();
    }
}

int main() {
    cin >> n;

    int numOfBomb =0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]) numOfBomb++;
        }
    }
    
    // 폭발 범위 입력
    vector<pair<int,int>> type0;
    vector<pair<int,int> > type1 = {{-2,0}, {-1, 0}, {0,0}, {1,0}, {2,0}};
    vector<pair<int,int> > type2 = {{-1,0}, {0, -1}, {0,0}, {1,0}, {0,1}};
    vector<pair<int,int> > type3 = {{-1, -1}, {-1, 1}, {0,0}, {1,-1}, {1,1}};
    
    bombRange.push_back(type0);
    bombRange.push_back(type1);
    bombRange.push_back(type2);
    bombRange.push_back(type3);


    // 폭탄 타입의 조합 생성 및 폭발 범위 계산
    backtracking(0, numOfBomb);

    // output
    cout << answer << '\n';
    return 0;
}
