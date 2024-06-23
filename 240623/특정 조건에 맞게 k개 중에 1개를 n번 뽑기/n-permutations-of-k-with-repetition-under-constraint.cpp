#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> num;
//연속하여 같은 숫자가 3번 이상 나오는 경우는 제외
void MakeNum(int curr_num){
    // 종료조건
    if(curr_num==n){
        for(int i=0; i<n; ++i){
            cout << num[i] << " ";
        }
        cout <<'\n';
        return;
    }
    
    // 재귀 호출
    for(int i=1; i<=k; ++i){
        if(curr_num>1 && num[curr_num-1]==i && num[curr_num-2]==i) continue;
        num.push_back(i);
        MakeNum(curr_num+1);
        num.pop_back();
    }

}
int main() {
    cin >> k >> n;

    MakeNum(0);

    return 0;
}