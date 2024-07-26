#include <iostream>
using namespace std;

string str, pattern;
// dp[i][j]: str의 i번째 문자와 pattern의 j번째 문자가 일치하는지 여부
bool dp[21][21];

void Init(){
    dp[0][0]=true; // 빈 문자열과 빈 패턴은 일치함

    //p의 문자가 *인 경우, *은 그 전의 문자와 0번 매칭될 경우
    for (int j = 1; j <=pattern.length(); ++j){
        if (pattern[j-1] == '*') dp[0][j] = dp[0][j-2];
    }
}

int main() {
    // input
    cin >> str >> pattern;
    int n=str.length(), m=pattern.length();

    // init
    Init();

    // solution
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            // 문자열(i-1번째)과 패턴(j-1번째)이 일치 || 패턴(j-1번째)이 '.'
            if(str[i-1]==pattern[j-1] || pattern[j-1]=='.') dp[i][j]=dp[i-1][j-1];

            // 패턴(j-1번째)이 '*'인 경우
            if(pattern[j-1]=='*'){
                // *이 1번 이상 매칭
                // =문자열(i-1번째)과 패턴(j-2번째)이 일치 || 패턴(j-2번째) '.'
                if(str[i-1]==pattern[j-2] || pattern[j-2]=='.') dp[i][j] = dp[i-1][j];
                // *이 0번 매칭
                else dp[i][j] = dp[i][j-2];
            }
        }
    }
    // output
    string answer = (dp[n][m]==true) ? "true":"false"; 
    cout << answer << '\n';
    return 0;
}