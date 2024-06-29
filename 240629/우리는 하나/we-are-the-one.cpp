#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, u, d, answer;
int arr[10][10];

vector<pair<int,int> > selectedCity;
bool visitedDFS[10][10]={false, };
bool visitedBFS[10][10]={false, };

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

bool CanGo(int x, int y, int diff){
    if(!InRange(x, y)) return false;
    // 방문한 칸 || !(u이상 && d이하)
    if(visitedBFS[x][y] || !(diff>=u && diff<=d)) return false;
    return true;
}

int BFS(){
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1)
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    int numOfCity = k; // k개의 도시를 선택했으니까 최소 k개
    queue<pair<int,int> > q;
    
    // visited 배열 초기화
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            visitedBFS[i][j]=false;
        }
    }

    //선택한 도시들(selectedCity)을 모두 queue에 넣어줌
    for(size_t i=0; i<selectedCity.size(); ++i){
        q.push(selectedCity[i]);
        visitedBFS[selectedCity[i].first][selectedCity[i].second]=true;
    }

    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int dir=0; dir<4; ++dir){
            int nx=x+dx[dir], ny=y+dy[dir], diff=abs(arr[x][y]-arr[nx][ny]);
            if(CanGo(nx, ny, diff)){
                q.push({nx, ny});
                numOfCity++;
                visitedBFS[nx][ny]=true;
            }
        }
    }
    
    return numOfCity;
}

// 재귀로 k개의 도시를 선택
void SelectCity(int curr_num){
    //종료 조건
    if(curr_num==k){
        answer=max(answer, BFS());
        return;
    }

    // 재귀 호출
    for(int row=0; row<n; ++row){
        for(int col=0; col<n; ++col){
            if(visitedDFS[row][col]) continue;
            
            selectedCity.push_back({row, col});
            visitedDFS[row][col] = true;
            SelectCity(curr_num+1);

            selectedCity.pop_back();
            visitedDFS[row][col] = false;
        }
    }
}

int main() {
    // input
    cin >> n >> k >> u >> d;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }
    
    // solution
    SelectCity(0);
    
    //output
    cout << answer << '\n';
    return 0;
}