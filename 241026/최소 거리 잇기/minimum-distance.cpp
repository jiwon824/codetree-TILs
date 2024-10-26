#include <iostream>
#include <iomanip> //setprecision
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 200;
const int MAX_M = 200;

int n, m;
int uf[MAX_N]; // i번째 점의 소속
vector<pair<int,int> > points; // {x, y}
vector<tuple<float,int,int> > edges; // {dist, a, b} a번 노드와 b번 노드의 거리 dist

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

float distBetweenTwoPoints(pair<int,int> a, pair<int,int> b){
    // 두 점 사이의 거리: sqrt((x_2 - x_1)^2 + (y_2 - y_1)^2)
    return sqrt(pow(b.first-a.first, 2) + pow(b.second-a.second, 2));
}

int main() {
    cin >> n >> m;
    // uf 배열 초기화
    for(int i=1; i<=n; ++i){
        uf[i]=i;
    }
    // n개 줄에 걸쳐 각 점의 좌표
    points.resize(n+1);
    for(int i=1; i<=n; ++i){
        int x, y;
        cin >> x >> y;
        points[i]={x, y};
    }
    // m개 줄에 걸쳐 각 선이 잇고 있는 정점의 번호
    for(int i=1; i<=m; ++i){
        int a, b;
        cin >> a >> b;
        myUnion(a, b);
    }

    // 각 점들을 잇는 모든 간선 추가
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            float dist = distBetweenTwoPoints(points[i], points[j]);
            edges.push_back({dist, i, j});
        }
    }

    // dist 순으로 정렬
    sort(edges.begin(), edges.end());
    
    float mstSum = 0.0;
    for(auto e : edges){
        float dist;
        int a, b;
        tie(dist, a, b)=e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        mstSum+=dist;
    }

    // 소수점 둘째 자리까지 출력
    cout << fixed << setprecision(2) << mstSum << '\n';
    return 0;
}