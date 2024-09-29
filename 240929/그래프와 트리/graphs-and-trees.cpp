#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 501;

int n, m, numOfTree;
vector<int> edges[MAX_N];
bool visited[MAX_N] = {false, };

void DFS(int x, vector<int> &v){
    for(int i=0; i<(int)edges[x].size(); ++i){
        int y=edges[x][i];
        if(visited[y]) continue;
        visited[y]=true;
        v.push_back(y);
        DFS(y, v);
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        // a b노드 연결
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // solution
    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;
        vector<int> cycle_check;

        visited[i]=true;
        cycle_check.push_back(i);
        DFS(i, cycle_check);

        //cycle_check에 들어있는 노드들의 간선 개수 검사
        int cnt =0;
        for(int j=0; j<(int)cycle_check.size(); ++j){
            int node=cycle_check[j];
            // node에 연결된 간선의 개수를 cnt에 누적
            cnt+=edges[node].size();
        }
        cnt/=2; // 양방향을 모두 간선에 추가했기 때문에 2나눠줌

        // 정점((int)cycle_check.size())의 수에 -1한 것과 간선의 수가 같으면 트리
        if((int)cycle_check.size()-1==cnt) numOfTree++;
    }

    // output
    cout << numOfTree << '\n';
    return 0;
}