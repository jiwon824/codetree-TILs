#include <iostream>
#include <vector>
#include <algorithm> // min({list})
using namespace std;

const int MAX_N = 100'001;

int n;
vector<int> edges[MAX_N];
bool visited[MAX_N]={false, };

int dp[MAX_N][2];
int parent[MAX_N]; // i번째 노드의 부모 노드
vector<int> children[MAX_N]; // i번째 노드의 자식 노드
bool isLeaf[MAX_N]={true, }; // i번째 노드가 리프 노드인지 여부

void PrintLog(){
    cout << "DP Table State\n";
    for(int i=1; i<=n; ++i){
        cout << "[" << i << "]" << " ";
        for(int j=0; j<2; ++j){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}

// child가 leaf가 아닌 경우 처리
void Process_Child_Non_Leaf(int x){
    // 초기값
    dp[x][0]=0, dp[x][1]=1;
    bool found_covered_child=false; // 아이템으로 커버된 자식 노드 존재 여부
    int min_diff = 1e9;

    for(int y : children[x]){
        // 부모인 경우 건너뜀
        if(parent[x]==y) continue;

        // 자식 노드가 리프 노드인 경우
        if(isLeaf[y]){
            dp[x][0]+=dp[y][1];
            found_covered_child=true;
        }
        else{
            // 자식 노드가 리프 노드가 아닌 경우
            // 손자 노드의 비용 합 계산
            int sum=0;
            for(int z : children[y]){
                sum += min(dp[z][0], dp[z][1]);
            }
            
            // 손자 노드들의 합, 자식 노드에 아이템을 놓은 경우, 놓지 않은 경우 중 최소값 선택
            int min_value = min({sum, dp[y][1], dp[y][0]});
            dp[x][1] += min_value;

            if (dp[y][1] < dp[y][0]) found_covered_child = true;

            min_diff = min(min_diff, dp[y][1]-dp[y][0]);
            dp[x][0] += min(dp[y][0], dp[y][1]);
        }
    }

    // x를 선택 안하는데, 선택한 x의 자식 y가 없다면 강제로 선택하는 게 가장 이득인 자식 선택
    if(!found_covered_child) dp[x][0]+=min_diff;
}

void DFS(int x){
    for(int y : edges[x]){
        if(visited[y]) continue;

        visited[y]=true; // 방문 체크
        isLeaf[x]=false; // 자식이 있으므로 non-leaf
        parent[y]=x; // y의 부모 x
        children[x].push_back(y);// x의 자식 y

        DFS(y);
    }

    if(isLeaf[x]) dp[x][0]=1e9, dp[x][1]=1;
    else Process_Child_Non_Leaf(x);
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        // 간선 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // solution
    visited[1]=true;
    DFS(1);

    // output
    cout << min(dp[1][0], dp[1][1]) << '\n';
    return 0;
}