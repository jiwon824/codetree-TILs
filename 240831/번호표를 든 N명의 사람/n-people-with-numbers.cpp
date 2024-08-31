#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 10000;
int n, t_max;
int stay_time[MAX_N];

// 무대에 capacity명까지 올라갈 수 있다고 했을 때,
// t_max 시간 안에 모든 사람이 무대를 마칠 수 있는지 여부
bool IsPossible(int capacity){
    // 무대에 올라간 사람을 관리하는 우선순위 큐. pq.size()=capacity
    // stay_time이 가장 적은 사람이 먼저 나와야 하기 때문에 최소힙이어야 함 
    priority_queue<int, vector<int>, greater<int>> pq;
    int time=0;
    for(int i=0; i<n; ++i){
        if(pq.size()==capacity){
            time+=pq.top();
            pq.pop();
        }
        pq.push(stay_time[i]);
    }
    return time<=t_max;
}

// 문제 요약
// 모든 사람이 무대에서 내려갈 때 까지 걸리는 시간이 t_max 넘지 않도록 하려고 할 때, 가능한 k의 최솟값
// n: 사람의 수
// stay_time: 각각의 사람이 무대에 머무르는 시간
// k(answer): 무대 수용 인원 (문제에서 요구하는 답)
int main() {
    // input
    cin >> n >> t_max;
    for(int i=0; i<n; ++i){
        cin >> stay_time[i];
    }

    // solution
    // 무대 최소 인원(left)은 1명, 최대 인원(right)은 n명이 될 것
    int left=1, right=n, answer=n;
    while(left<=right){
        int mid = (left+right)/2;
        if(IsPossible(mid)) {
            // k의 최소값을 구해야 하므로 가능하다면 인원수를 줄여서 탐색
            right = mid-1;
            answer =mid;
        }
        else left = mid+1; // 불가능하다면 인원수를 늘려서 탐색
    }

    // output
    cout << answer << '\n';
    return 0;
}