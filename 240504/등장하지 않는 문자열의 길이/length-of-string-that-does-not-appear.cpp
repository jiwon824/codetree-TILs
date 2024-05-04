/*
"ABCDABC"가 주어졌을 때,
int max_len =0; // 부분문자열의 길이
1. 길이1 부분 문자열 A, B, C, D, A, B, C 검사

 A가 2번 나옴(2번이상 나왔으니 max_len=1 갱신)
====
A가 2번 나온 순간 해당 부분은 검사할 필요 없음
(이해를 돕기 위해 적음)
B가 2번 나옴(max_len=1)
C가 2번 나옴(max_len=1)
D는 1번 나왔지만 앞에 다른 길이가 1인 문자열이 2번이상 나왔기 때문에 관계없음
A가 2번 나옴(max_len=1)
B가 2번 나옴(max_len=1)
C가 2번 나옴(max_len=1)
====

2. 길이2 부분 문자열 AB, AC,AD, AA, AB,AC 등등 검사
AB가 2번 나옴(2번 이상 나왔으니 max_len=2 갱신)

*/
#include <iostream>
#include <string>

using namespace std;

int n;
string Make_Substring(string base, int len, int idx);
bool Check(string base, string sub);

bool Check(string base, string sub){
    //cout << "Check()\n";
    // str과 sub 비교
    int cnt =0;
    // base="ABCDABC", sub="A"인 경우 0번 인덱스부터 6번 인덱스까지 검사
    // base="ABCDABC", sub="AB"인 경우 0번 인덱스부터 5번 인덱스까지 검사
        // (0,1)(1,2)(2,3)(3,4)(4,5)(5,6) 이렇게 같은지 검사하기 때문
    for(int i=0; i<=n-sub.length(); i++){
        string tmp_str = Make_Substring(base, sub.length(), i);
        //cout << tmp_str<<'\n';
        if(sub==tmp_str) cnt++;
    }
    if(cnt>=2) return true;
    return false;
}

string Make_Substring(string base, int len, int idx){
    string substr  ="";
    for(int i=idx; i<len+idx; i++){
        if(i>=base.length()) continue;
        substr = substr+base[i];
    }
    return substr;
}

int main() {
    string str;
    cin >> n >> str;

    int answer=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            // j번째 인덱스부터 길이가 i인 단어
            string substr = Make_Substring(str, i, j);
            // cout << substr << '\n';

            // 부분 문자열이 2번 연속 나왔다면 
            if(Check(str, substr)) answer = i+1;
            //cout << substr << " " <<cnt <<'\n';

        }
    }
    cout << answer;

    return 0;
}