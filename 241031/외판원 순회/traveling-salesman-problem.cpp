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
        // 0은 이동할 수 없음을 뜻하며, arr[i][i]=0
        // 즉, arr[nodeA][nodeB]==0이라면 불가능한 경로 이므로 -1 반환
        if(arr[nodeA][nodeB]==0) return -1;

        // a->b로 가는 비용을 더함
        cost+=arr[nodeA][nodeB];
    }
    return cost;
}

void pickNode(int numOfPick){
    // n개를 선택한 경우
    if(numOfPick==n){
        // 1로 돌아와야 함
        picked.push_back(1);
        int cost = calculateCost();
        answer = (cost!=-1) ? min(answer, cost) : answer;
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