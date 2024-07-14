#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > lines;
int dp[1001]; // dp[i] i가 끝점일 경우 i까지 가장 많은 선분의 수

int main() {
    // input
    cin >> n;
    for(int i=1; i<=n; ++i){
        int x1, x2;
        cin >> x1 >> x2;
        lines.push_back({x1, x2});
    }

    // solution
    sort(lines.begin(), lines.end());
    // 두 점이 겹치지 않기 위한 조건 (a1, a2) (b1, b2)
    // a2 < b1 || b2 < a1
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        int a1=lines[i].first, a2=lines[i].second;
        for(int j=0; j<i; ++j){
            int b1=lines[j].first, b2=lines[j].second;
            if(a2 < b1 || b2 < a1)
                dp[i]= max(dp[i], dp[j]+1);
        }
        
    }

    // output
    int answer=0;
    for(int i=1; i<=n; ++i){
        answer = max(answer, dp[i]);
    }
    cout << answer <<'\n';

    return 0;
}