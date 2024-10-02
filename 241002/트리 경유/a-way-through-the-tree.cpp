#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1<<20;

int n, q; // 2^{32}-1
bool visited[MAX_N] = {false, };

int Check_route(int x){
    vector<int> route;
    bool isPossible = true;
    while(x>=1){
        // 경로 중에 방문했던 노드가 있다면 이동 실패
        if(visited[x]) isPossible=false;

        route.push_back(x);
        x/=2;
    }
    
    // 이동 가능하면 노드 방문 체크 후, 0 return
    if(isPossible) {
        int node=route[0];
        visited[node]=true;
        return 0;
    }
    else{
        // 이동 불가능하다면 루트노드부터 visited[i]=true인 최초의 노드 번호 return
        for(int i=(int)route.size()-1; i>=0; --i){
            int node = route[i];
            if(visited[node]) return node;
        }
    }

    // 잘못된 경우
    return -1;
}

int main() {
    cin >> n >> q;
    // 두 번째 줄부터 차례로 q개의 줄에 걸쳐 목적지 노드의 번호가 주어집니다.
    while(q--){
        int dest;
        cin >> dest;
        // 어떤 노드 x의 부모 노드는 x/2 (소수점 버림)
        // 목적지 노드가 주어졌을 때, 그 노드에서 루트까지의 경로는 하나
        cout << Check_route(dest) << '\n';
    }
    return 0;
}