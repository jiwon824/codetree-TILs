#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, answer=INT_MAX, sumOfAll;
int arr[21];
bool visisted[21]={false, };
vector<int> selected;

// idx: 현재 선택한 원소의 idx
void MakeGroup(int cnt, int idx){
    // 종료조건
    if(cnt==n){
        int sum=0;
        for(size_t i=0; i<selected.size(); ++i){
            sum+=selected[i];
        }
        answer=min(answer, abs((sumOfAll-sum)-sum));
        return;
    }

    // 재귀호출
    for(int i=idx; i<2*n; ++i){
        if(visisted[i]) continue;

        selected.push_back(arr[i]);
        visisted[i]=true;
        MakeGroup(cnt+1, i);
        selected.pop_back();
        visisted[i]=false;
    }

}

int main() {
    // input
    cin >> n;
    for(int i=0; i<2*n; ++i){
        cin >> arr[i];
        sumOfAll += arr[i];
    }

    // solution
    MakeGroup(0, 0);

    // output
    cout << answer << '\n';
    return 0;
}