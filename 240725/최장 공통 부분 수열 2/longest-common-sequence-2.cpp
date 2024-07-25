#include <iostream>
using namespace std;

string a, b;
int dp[1001][1001];


int main() {
    // input
    cin >> a >> b;
    int n=a.length(), m=b.length();

    // solution
    // 1. 초기 설정
    dp[0][0] = (a[0]==b[0]) ? 1:0;
    for(int i=1; i<=n; ++i){
        if(a[i]==b[0]) dp[i][0]=1;
        else dp[i][0]=dp[i-1][0];
    }
    for(int j=1; j<=m; ++j){
        if(a[0]==b[j]) dp[0][j]=1;
        else dp[0][j]=dp[0][j-1];
    }

    // 2. 상태 전이
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // 3. DP테이블을 이용하여 LCS 문자 찾기
    int i=n, j=m;
    string answer="";
    while(i > 0 && j > 0){
        if(a[i-1]==b[j-1]){
            // 같으면 answer에 추가
            answer= a[i-1]+answer;
            --i;
            --j;
        }
        else{
            // 다르면 더 큰쪽으로 이동
            if(dp[i-1][j]>dp[i][j-1]) --i;
            else --j;
        }
    }

    // output
    cout << answer << '\n';
    return 0;
}