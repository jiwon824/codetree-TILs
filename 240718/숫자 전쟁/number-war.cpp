#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    // input
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // solution
    // i는 a의 카드 인덱스 j는 b의 카드 인덱스
    for(int i=n-1; i>=0; --i){
        for(int j=n-1; j>=0; --j){
            int playScore=0, discardScore=0;
            if(a[i]>b[j]){
                // 카드대결(b가 들고 있는 카드 점수 획득)과 카드 버리기 경우 중 큰 경우를 선택
                playScore=b[j];
                if(j+1<n) playScore+=dp[i][j+1];
                if(i+1<n && j+1<n) discardScore=dp[i+1][j+1];
                dp[i][j]=max(playScore, discardScore);
            }
            else if (a[i]<b[j]){
                if(i+1<n) playScore=dp[i+1][j];
                if(i+1<n && j+1<n) discardScore=dp[i+1][j+1];
                dp[i][j] = max(playScore, discardScore);
            }
            else dp[i][j] = (i+1<n && j+1<n) ? dp[i+1][j+1] : 0;
        }
    }

    // output
    cout << dp[0][0] << '\n';
    return 0;
}