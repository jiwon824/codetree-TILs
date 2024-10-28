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

int main() {
    // [input] 점의 개수 n
    cin >> n;
    // [input] n개의 줄에 걸쳐 각 점의 좌표가 한 줄에 하나씩
    for(int i=0; i<n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        points.push_back({x, y, z});
    }

    // [solution] 1. 모든 점에 대해 간선 정보 구하기
    // i번 점과 j번 점의 좌표 차 중 가장 작은 값을 edges에 저장
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int ax, ay, az;
            tie(ax, ay, az)=points[i];
            int bx, by, bz;
            tie(bx, by, bz)=points[j];

            // 임의의 두 개의 점을 연결할 때 드는 비용
            // 두 점의 x좌표의 차, 두 점의 y좌표의 차, 두 점의 z좌표의 차 중 가장 작은 값
            int min_diff=min({abs(ax-bx), abs(ay-by), abs(az-bz)});
            edges.push_back({min_diff, i, j});
        }
    }
    
    // 간선 정렬
    sort(edges.begin(), edges.end());

    //Union-find
    int answer =0;
    for(auto e : edges){
        int diff, a, b;
        tie(diff, a, b)=e;
        if(myFind(a)==myFind(b)) continue;
        myUnion(a, b);
        answer+=diff;
    }

    cout << answer << '\n';
    return 0;
}