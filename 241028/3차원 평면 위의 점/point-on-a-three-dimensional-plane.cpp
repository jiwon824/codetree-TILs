#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int MAX_N = 100'000;

int n;
int uf[MAX_N+1];
vector<tuple<int,int,int> > points; // points[i]: i번 점의 좌표{x, y, z}
vector<tuple<int,int,int> > edges; // a와 b번 점을 잇는 간선의 길이 diff {diff, a, b};

int myFind(int x){
    if(uf[x]==x) return x;
    return uf[x]=myFind(uf[x]);
}
void myUnion(int x, int y){
    x=myFind(x), y=myFind(y);
    if(x==y) return;
    uf[x]=y;
}

bool cmpSec(tuple<int,int,int> &v1, tuple<int,int,int> &v2){
    return get<1>(v1)<get<1>(v2);
}
bool cmpThr(tuple<int,int,int> &v1, tuple<int,int,int> &v2){
    return get<2>(v1)<get<2>(v2);
}

void makeEdges(){
    // x 좌표를 기준으로 정렬한 후, 인접 노드 간의 간선 저장
    sort(points.begin(), points.end());
    for(int i=0; i<n; ++i){
        int ax, ay, az;
        tie(ax, ay, az)=points[i];
        int bx, by, bz;
        tie(bx, by, bz)=points[i+1];

        // 임의의 두 개의 점을 연결할 때 드는 비용
        // 두 점의 x좌표의 차, 두 점의 y좌표의 차, 두 점의 z좌표의 차 중 가장 작은 값
        int min_diff=min({abs(ax-bx), abs(ay-by), abs(az-bz)});
        edges.push_back({min_diff, i, i+1});
    }

    // y 좌표를 기준으로 정렬한 후, 인접 노드 간의 간선 저장
    sort(points.begin(), points.end(), cmpSec);
    for(int i=0; i<n; ++i){
        int ax, ay, az;
        tie(ax, ay, az)=points[i];
        int bx, by, bz;
        tie(bx, by, bz)=points[i+1];

        // 임의의 두 개의 점을 연결할 때 드는 비용
        // 두 점의 x좌표의 차, 두 점의 y좌표의 차, 두 점의 z좌표의 차 중 가장 작은 값
        int min_diff=min({abs(ax-bx), abs(ay-by), abs(az-bz)});
        edges.push_back({min_diff, i, i+1});
    }

    // z 좌표를 기준으로 정렬한 후, 인접 노드 간의 간선 저장
    sort(points.begin(), points.end(), cmpThr);
    for(int i=0; i<n; ++i){
        int ax, ay, az;
        tie(ax, ay, az)=points[i];
        int bx, by, bz;
        tie(bx, by, bz)=points[i+1];

        // 임의의 두 개의 점을 연결할 때 드는 비용
        // 두 점의 x좌표의 차, 두 점의 y좌표의 차, 두 점의 z좌표의 차 중 가장 작은 값
        int min_diff=min({abs(ax-bx), abs(ay-by), abs(az-bz)});
        edges.push_back({min_diff, i, i+1});
    }
}

int main() {
    // [input] 점의 개수 n
    cin >> n;
    // [input] n개의 줄에 걸쳐 각 점의 좌표가 한 줄에 하나씩
    for(int i=0; i<n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        points.push_back({x, y, z});
    }

    // [solution] 1. 간선 구하기
    makeEdges();

    // [solution] 2. 간선 정렬
    sort(edges.begin(), edges.end());

    // [solution] 3. Union-find
    int answer =0;
    for(auto e : edges){
        int diff, a, b;
        tie(diff, a, b)=e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        answer+=diff;
    }

    // [output] answer 출력
    cout << answer << '\n';
    return 0;
}