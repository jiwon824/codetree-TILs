#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> answer;

void Choose(int curr, int cnt){
    // 종료 조건
    if(curr == n+1){
        if(cnt==m){
            for(auto e :answer){
                cout << e << " ";
            }
            cout << '\n';
        }
        return;
    }

    // 재귀 호출

    answer.push_back(curr);
    Choose(curr+1, cnt+1);
    answer.pop_back();
    Choose(curr+1, cnt);
}
int main() {
    cin >> n >> m;

    Choose(1, 0);

    return 0;
}