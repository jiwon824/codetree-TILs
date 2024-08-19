#include <iostream>
#define MAX_N 100000
using namespace std;

int energy[MAX_N];
int cost[MAX_N];
int minCost[MAX_N]; //minCost[i]: 0~i 중 최소 비용

int main() {
    int n;
    cin >> n;
    // 장소와 장소를 이동할 때 소모하는 에너지
    // energy[0]=0이기 때문에 1부터 시작함
    for(int i=1; i<n; ++i){
        cin >> energy[i];
    }
    // 각 장소마다 에너지 1을 채우는데 필요한 비용
    for(int i=0; i<n; ++i){
        cin >> cost[i];
    }

    // i번째 장소까지 올 때까지의 최소비용
    // cost[4]={1, 5, 2, 4}라면 minCost[4]={1, 1, 1, 1}이 된다. 
    // cost[4]={5, 2, 1, 4}라면 minCost[4]={5, 2, 1, 1}이 된다. 
    minCost[0]=cost[0];
    for(int i=1; i<n; ++i){
        minCost[i]=min(minCost[i-1], cost[i]);
    }

    // 제일 왼쪽 장소에서 제일 오른쪽 장소까지 이동할 때 드는 최소 비용
    long long answer=0;
    for(int i=0; i<n; ++i){
        answer+=energy[i]*minCost[i-1];
    }
    cout << answer << '\n';
    return 0;
}