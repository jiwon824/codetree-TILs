#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N =50;

int n;
int arr[MAX_N+1][MAX_N+1]; // 주어지는 격자 정보
vector<pair<int,int> > bases; // 기지 좌표 {x, y}
vector<tuple<int,int,int> > edges; //{dist, a, b}
int uf[MAX_N*MAX_N+1]; // 이차원 배열을 일차원으로 치환

bool inRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

int findBaseNum(int x, int y){
    for(int i=0; i<(int)bases.size(); ++i){
        if(bases[i].first==x && bases[i].second==y) return i;
    }
    return -1;
}

// BFS로 기지 간의 거리(=간선)를 구함
void BFS(int i, int j, int baseIdx){
    // 상하좌우
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};

    queue<tuple<int,int,int> > q;// {x, y, dist} dist는 (i, j)로부터의 거리를 의미
    bool visited[MAX_N+1][MAX_N+1] = { false, };

    q.push({i, j, 0});
    visited[i][j]=true;

    while(!q.empty()){
        int qSize = q.size();
        for(int qIdx=0; qIdx<qSize; ++qIdx){
            int x, y, dist;
            tie(x, y, dist)=q.front();
            q.pop();
            // 4방향 탐색
            for(int dir=0; dir<4; ++dir){
                int nx=x+dx[dir], ny=y+dy[dir];
                // 범위를 벗어남 || 갈 수 없는 칸 || 이미 방문한 칸
                if(!inRange(nx, ny) || arr[nx][ny]==-1 || visited[nx][ny]) continue;

                visited[nx][ny]=true;
                q.push({nx, ny, dist+1});
                // (x, y)가 활성화되지 않은 기지일 경우 edge 추가
                if(arr[nx][ny]==2) {
                    int a=baseIdx, b=findBaseNum(nx, ny);
                    edges.push_back({dist+1, a, b});
                }
            }
        }
    }
}

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

// 모든 기지를 활성화하기 위한 최소 비용 계산
int kruskal() {
    // uf 배열 초기화(0-based)
    for(int i=0; i<n; ++i){
        uf[i]=i;
    }

    // 거리가 짦은 순으로 이어야 하기 때문에
    sort(edges.begin(), edges.end());

    // 기지를 연결하며, dist의 합을 구함
    int distSum=0;
    for(auto e: edges){
        int dist, a, b;
        tie(dist, a, b) = e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        distSum+=dist;
    }

    // 연결되지 않은 기지가 있다면 -1 반환
    for(int i=1; i<(int)bases.size(); ++i){
        if(myFind(0)!=myFind(i)) return -1;
    }
    
    return distSum;
}

// 화성은 n x n모양의 격자 형태
// 여러 기지들이 건설. 이 중 단 한개의 기지만이 활성화
// 활성화된 기지를 바탕으로 화성에 있는 모든 기지를 활성화
int main() {
    // input
    cin >> n;
    // 0-based
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
            if(arr[i][j]==1 || arr[i][j]==2) bases.push_back({i, j});
        }
    }
    
    // 각 기지에서 BFS 실행하여 간선(거리) 계산
    for (int i = 0; i < bases.size(); ++i) {
        BFS(bases[i].first, bases[i].second, i);
    }

    cout << kruskal() << '\n';
    return 0;
}