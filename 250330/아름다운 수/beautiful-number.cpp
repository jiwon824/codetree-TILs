#include <iostream>
#include <vector>
using namespace std;

int n;
int answer=0;
vector<int> num;

bool beautifulCheck(){
    int checkIdx =0;
    while(checkIdx<num.size()){
        int base = num[checkIdx];
        for(int j=checkIdx; j<checkIdx+base; j++){
            if(num[j]!=base)return false;
        }
        checkIdx+=num[checkIdx];
    }
    return true;
}

void backtracking(int cnt){
    // 종료 조건
    if(cnt>=n){
        if(beautifulCheck()){
            answer++;
        }
        return;
    }
    // 재귀
    for(int i=1; i<=4; i++){
        num.push_back(i);
        backtracking(cnt+1);
        num.pop_back();
    }
}

int main() {
    cin >> n;

    backtracking(0);
    cout << answer << '\n';
    return 0;
}
