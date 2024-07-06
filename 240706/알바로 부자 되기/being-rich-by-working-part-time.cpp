#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX 1000000001

using namespace std;

int n;
vector<tuple<int,int,int> > workInfo;
int dp[1001];

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        int s, e, p;
        cin >> s >> e >> p;
        workInfo.push_back({s, e, p});
        dp[i]=p; // 최소 i번째 하나는 겹치지 않게 일 할 수 있음
    }

    // solution
    for(int i=1; i<n; ++i){
        int s1, e1, p1;
        tie(s1, e1, p1)=workInfo[i];
        for(int j=0; j<i; ++j){
            int s2, e2, p2;
            tie(s2, e2, p2)=workInfo[j];
            if(e2<s1){
                dp[i]=max(dp[i], dp[j]+p1);
            }
        }
    }
    
    // output
    int answer=0;
    for(int i=0; i<n; ++i){
        answer=max(answer, dp[i]);
    }
    cout << answer <<'\n';
    return 0;
}