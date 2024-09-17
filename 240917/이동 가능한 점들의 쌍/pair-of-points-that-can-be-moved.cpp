#include <iostream>
using namespace std;

const int MAX_N = 201;

int n, m, p, q;
int graph[MAX_N][MAX_N];


// [초기화]
void Init(){
    // 1. graph를 1e9로 초기화
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            graph[i][j]=1e9;
        }
    }
    // (graph[i][i]=0)인 게 일반적이나, 문제에서 빨간점을 반드시 포함해야 한다고 했으므로)
    for(int i=1; i<=p; ++i){
        graph[i][i]=0;
    }
}

int main() {

    // [입력] m개의 graph[s][e]=c;
    cin >> n >> m >> p >> q;
    // [초기화]
    Init();
    for(int i=0; i<m; ++i){
        // 출발점 번호, 도착점 번호, 비용
        int s, e, c;
        cin >> s >> e >> c;
        graph[s][e]=c;
    }

    // solution
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    // q개의 출발 도착점에 대해 
    long long numOfRoute=0, sumOfCost=0;
    while(q--){
        int s, e;
        cin >> s >> e;

        // 빨간점(1~p)를 적어도 1개 반드시 포함해야 한다.
        int dist = 1e9;
        for(int i=1; i<=p; ++i){
            dist=min(dist, graph[s][i]+graph[i][e]);
        }

        // 불가능하다면 패스
        if(dist==1e9) continue;

        numOfRoute++;
        sumOfCost+=dist;
    }

    // output
    cout << numOfRoute << '\n' << sumOfCost <<'\n';
    return 0;
}