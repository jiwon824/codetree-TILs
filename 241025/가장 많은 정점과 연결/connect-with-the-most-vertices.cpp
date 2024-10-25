#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100'000;

int n, m, k;
int uf[MAX_N+1];
vector<pair<int,int> > node_info; // {cost, node_num}

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

int main() {
    cin >> n >> m >> k;
    // 최소 비용을 찾기 위해서는 최소 비용이 적힌 노드에 다른 노드를 연결해야 함
    int minNode, minNodeNum=1e9;
    for(int i=1; i<=n; ++i){
        int cost;
        cin >> cost;
        node_info.push_back({cost, i});
        uf[i]=i;
    }
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        myUnion(a, b);
    }
    
    // 비용이 작은 노드들을 연결하기 위해 정렬
    sort(node_info.begin(), node_info.end());

    pair<int, int> min_node=node_info[0];
    int curr_cost=0;
    for(auto e : node_info){
        if(e.second==min_node.second) continue;

        if(myFind(min_node.second)!=myFind(e.second)){
            myUnion(min_node.second, e.second);
            curr_cost+= min_node.first+e.first;
        }
        if(curr_cost>k) break;
    }

    if(curr_cost>k) cout << "NO\n";
    else cout << curr_cost << '\n';
    return 0;
}