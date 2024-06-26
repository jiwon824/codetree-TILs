#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;
int arr[11][11];
bool visited[11]={false, };
vector<int> col_idx;

int FindMinNum(){
    int minNum=10000;
    for(int i=0; i<n; ++i){
        minNum=min(minNum, arr[i][col_idx[i]]);
    }
    return minNum;
}

void Choose(int curr){
    // 종료 조건
    if(curr==n){
        answer=max(answer, FindMinNum());
        return;
    }

    // 재귀 호출
    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        col_idx.push_back(i);
        visited[i]=true;
        Choose(curr+1);
        col_idx.pop_back();
        visited[i]=false;
    }
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> arr[i][j];
        }
    }

    Choose(0);
    
    cout << answer <<'\n';
    return 0;
}