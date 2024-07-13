#include <iostream>
using namespace std;

int n, sum;
int arr[101];
int dp[100001]; //dp[i]: 그룹A의 합

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    // init
    dp[0]=0;
    for(int i=1; i<=sum; ++i){
        dp[i] = 100001;
    }
    
    // solution
    // 한 개의 수를 중복하여 선택할 수 없으므로 for문을 거꾸로 돌아야 함
    for(int i=0; i<n; ++i){
        for(int j=sum; j>=0; --j){
            // 범위 밖 접근 || 아직 초기화되지 않은 수
            if(j-arr[i]<0 || dp[j-arr[i]]>sum) continue;

            dp[j]=min(dp[j], dp[j-arr[i]]+arr[i]);
        }
    }

    // output
    int answer = 100001;
    for(int i=1; i<=sum; ++i){
        if(dp[i]>sum) continue;
        
        int group_A = dp[i], group_B = sum-group_A;
        int diff= abs(group_A-group_B);

        answer = min(answer, diff);
    }
    cout << answer << '\n';
    
    return 0;
}