#include <iostream>
#include <vector>

using namespace std;

int n; // 자릿수
int num_of_beauty; // 아름다운 숫자의 갯수
vector<int> v; // 숫자의 조합을 만들 벡터

bool IsBeautiful(string num){
    bool answer = true;
    for(int idx=0; idx<num.length(); idx+=num[idx]){
        // num[idx]가 1이면 num[idx]부터 num[idx]까지(길이 1 검사)
        // num[idx]가 2면 num[idx]부터 num[idx+1]까지(길이 2 검사: idx, idx+1)
        // num[idx]가 3이면 num[idx]부터 num[idx+2]까지(길이 3 검사: idx, idx+1, idx+2)
        // num[idx]가 4면 num[idx]부터 num[idx+3]까지(길이 4 검사: idx, idx+1, idx+2, idx+3)
        string sub_str="";
        for(int j=idx; j<idx+num[idx]; j++){
            sub_str=sub_str+num[j];
        }
        //cout << sub_str << '\n';
        //sub_str 아름다운지 검사
        for(int j=1; j<sub_str.length(); j++){
            if(sub_str[j-1]!=sub_str[j]) answer=false;
        }
        if(!answer) break; // 아름답지 않은 조합이 섞여 있으면 아름다운 수가 아니므로 더이상 검사할 필요없음
    }
    return answer;
}

void Make_Num(int curr_num){
    //종료 조건
    if(curr_num>n){
        string num="";
        for (auto e : v){
            num = num+(char)e;
        }
        bool answer = IsBeautiful(num);
        if(answer) num_of_beauty++;
        return;
    }

    //재귀 호출
    //1이상 4이하의 숫자로만 이루어진 숫자 조합
    for(int i=1; i<=4; i++){
        v.push_back(i);
        Make_Num(curr_num+1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    Make_Num(1);
    cout << num_of_beauty <<'\n';
    return 0;
}