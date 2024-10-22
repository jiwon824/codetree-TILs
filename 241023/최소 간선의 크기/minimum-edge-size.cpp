#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 100'000;

int n, m, s_node, e_node;
int uf[MAX_N];
vector<tuple<int, int,int> > edges; // edges[i]={x, y, sat};

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}

void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    uf[x]=y;
}

// sat이상의 간선들만 union 해주기
bool isPossible(int sat){
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    
    for(int i=0; i<m; ++i){
        int a, b, s;
        tie(a, b, s)=edges[i];
        if(s>=sat) myUnion(a, b);
    }

    return myFind(s_node) == myFind(e_node);
}

int main() {
    cin >> n >> m;
    cin >> s_node >> e_node;

    int maxSat = 0;
    for(int i=0; i<m; ++i){
        int a, b, s;
        cin >> a >> b >> s;
        myUnion(a, b);
        edges.push_back({a, b, s});
        maxSat=max(maxSat, s);
    }

    // 만족도를 기준으로 이진 탐색
    // 현재 만족도 이상인 간선들만 사용해서 start와 end가 연결되는지 확인
    // 연결된다면 더 큰 만족도 시도, 연결되지 않는다면 더 작은 만족도 시도
    int left = 1, right = maxSat;
    int answer = 0;
    while(left<=right){
        int mid=(left+right)/2;
        if(isPossible(mid)) {
            answer=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    cout << answer << '\n';
    return 0;
}