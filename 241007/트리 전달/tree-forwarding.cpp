#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n, m;
int parent[MAX_N];
int score[MAX_N];// i번 노드의 초기 점수
int dp[MAX_N]; // dp[i]=dp[parent[i]]+score[i] ==부모의 점수+내 점수

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> parent[i];
    }
    // 연산의 수
    for(int i=0; i<m; ++i){
        int node, num;
        cin >> node >> num;
        score[node]+=num;
    }

    // solution
    for(int i=1; i<=n; ++i){
        if(parent[i]==-1) {
            dp[i]=score[i];
            continue;
        }
        dp[i]=dp[parent[i]]+score[i];
    }

    // output
    for(int i=1; i<=n; ++i){
        cout << dp[i] << " ";
    }
    return 0;
}