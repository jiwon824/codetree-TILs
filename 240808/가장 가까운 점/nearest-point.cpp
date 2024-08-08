#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 가장 가까운 순, 값이 가장 작은 점이 top에 오도록 해야 함(-)
    //원점과 특정 점 (x, y)과의 거리는 ∣x∣+∣y∣ 로 생각
    priority_queue<tuple<int,int,int> > pq; // dist, x, y
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        pq.push({-(x+y), -x, -y});
    }

    // m번 원점으로 부터 가장 가까운 점을 잡아 2씩 더해주는 작업을 진행
    while(m--){
        int dist, x, y;
        tie(dist, x, y) = pq.top();
        pq.pop();
        x=(-x+2);
        y=(-y+2);
        dist=x+y;
        pq.push({-dist, -x, -y});
    }

    // 가장 원점에 가까운 점의 (x, y)값을 공백을 사이에 두고 출력
    int answerX, answerY;
    tie(ignore, answerX, answerY) = pq.top();
    cout << -answerX << " " << -answerY <<'\n';
    return 0;
}