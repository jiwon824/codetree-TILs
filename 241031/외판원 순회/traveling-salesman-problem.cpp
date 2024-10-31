#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10;

int n, answer=1e9;
int arr[MAX_N+1][MAX_N+1];
vector<int> picked;
bool visited[MAX_N+1] = {false, };

int calculateCost(){
    int cost=0;
    for(int i=1; i<(int)picked.size(); ++i){
        int nodeA=picked[i-1], nodeB=picked[i];
        // a->b로 가는 비용을 
        cost+=arr[nodeA][nodeB];
    }
    return cost;
}

void pickNode(int numOfPick){
    // n개를 선택한 경우
    if(numOfPick==n){
        // 1로 돌아와야 함
        picked.push_back(1);
        answer = min(answer, calculateCost());
        // 다음 순열 계산해야 하므로 1 제거
        picked.pop_back();
        return;
    }

    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;

        picked.push_back(i);
        visited[i]=true;

        pickNode(numOfPick+1);

        picked.pop_back();
        visited[i]=false;
    }
}

int main() {
    // input
    cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> arr[i][j];
        }
    }
    
    // 선택한 노드 1개(=1번 노드)
    picked.push_back(1);
    visited[1]=true;
    pickNode(1);

    // output
    cout << answer << '\n';
    return 0;
}