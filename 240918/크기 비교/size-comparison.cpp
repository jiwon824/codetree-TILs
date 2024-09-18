#include <iostream>
using namespace std;

const int MAX_N=101;

int n, m;
int graph[MAX_N][MAX_N];

void Init(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            graph[i][j]=0; // 갈 수 없음
        }
        graph[i][i]=1; // 갈 수 있음(자기자신)
    }
}

int main() {
    // input
    cin >> n >> m;
    Init();
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a][b]=1;
    }

    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(graph[i][k]==0 || graph[k][j]==0) continue;
                // i->k==1 k->j==1이면 i->j 이동 가능
                graph[i][j]=1;
            }
        }
    }

    for(int i=1; i<=n; ++i){
        int unknown=0;
        for(int j=1; j<=n; ++j){
            if(graph[i][j]==0 && graph[j][i]==0) unknown++;
        }
        cout << unknown << '\n';
    }
    return 0;
}