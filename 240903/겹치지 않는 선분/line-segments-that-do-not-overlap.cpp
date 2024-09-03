#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

// 입력으로 주어지는 x1 끼리는 겹쳐져 주어지지 않으며, x2 끼리도 겹쳐져 주어지지 않음
vector<pair<int,int> > lines;
int lMax[MAX_N];
int rMin[MAX_N];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back({x1, x2});
    }

    sort(lines.begin(), lines.end());
    
    // 겹치지 않는 선분:
    // 현재 선분의 시작점이 이전 최대 끝점보다 크면서
    // 현재 선분의 끝점이 다음 선분의 시작점보다 작음

    lMax[0]=lines[0].second;
    for(int i=1; i<n; ++i){
        lMax[i]=max(lMax[i-1], lines[i].second);
    }

    rMin[n-1]=lines[n-1].second;
    for(int i=n-2; i>=0; --i){
        rMin[i]=min(rMin[i+1], lines[i].second);
    }

    int answer=0;
    for(int i=0; i<n; ++i){
        // cout << lMax[i] << " " << lines[i].second << " " << rMin[i] << '\n';
        // x1, x2는 겹쳐지게 주어지지 않으므로 x2가 겹친다면 자신과 비교한 것
        if(lMax[i]<=lines[i].second && lines[i].second<=rMin[i]) answer++;
    }
    cout << answer << '\n';
    return 0;
}