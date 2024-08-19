#include <iostream>
#define MAX_N 100000
using namespace std;

long long energy[MAX_N];
long long cost[MAX_N];

int main() {
    int n;
    cin >> n;
    // 장소와 장소를 이동할 때 소모하는 에너지
    for(int i=0; i<n-1; ++i){
        cin >> energy[i];
    }
    // 각 장소마다 에너지 1을 채우는데 필요한 비용
    for(int i=0; i<n; ++i){
        cin >> cost[i];
    }

    // 제일 왼쪽 장소에서 제일 오른쪽 장소까지 이동할 때 드는 최소 비용
    long long min_cost = cost[0]; // i번째 장소까지 올 때까지의 최소비용
    long long answer=0;
    for(int i=0; i<n-1; ++i){
        min_cost = min(min_cost, cost[i]);
        answer+=energy[i]*min_cost;
    }
    cout << answer << '\n';
    return 0;
}