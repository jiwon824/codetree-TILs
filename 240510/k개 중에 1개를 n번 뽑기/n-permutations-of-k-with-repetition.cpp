#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

void Choose(int curr_num){
    // 종료 조건
    if(curr_num>n){
        for(auto e: v){
            cout << e << " ";
        }
        cout << '\n';
        return;
    }

    // 재귀 호출
    // 1이상 k이하의 숫자를 하나 선택
    for(int i=1; i<=k; i++){
        v.push_back(i);
        Choose(curr_num+1);
        v.pop_back();
    }
}
int main() {
    cin >> k >> n;
    Choose(1);
    return 0;
}