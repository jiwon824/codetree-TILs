#include <iostream>
#include <algorithm>
using namespace std;

int n, k; //n개의 돌, 점프 가능 거리 k
int rock[101];

// max_val이 가장 큰 수여야 하기 때문에
// k 거리 이내의 돌 중, max_val보다 큰 수는 밟을 수 없음(작거나 같아야 함)
bool IsPossible(int max_val){
    //cout << "max_val=" << max_val << '\n';
    int available_idx[101]={};
    int cnt=0;
    for(int i=0; i<n; i++){
        if(rock[i]<=max_val){
            available_idx[cnt++] =i;
        }
    }
/*
    cout << "cnt=" << cnt << '\n';
    for(int i=0; i<n; i++){
        cout << available_idx[i] << " ";
    }
    cout << '\n';
*/  

    for(int i=1; i<cnt; i++){
        int dist = available_idx[i]-available_idx[i-1];
        if(dist>k) return false;
    }
    if(available_idx[0]>k) return false;
    
    return true;
}

int main() {
    cin >> n >> k;
    int max_num =0;
    for(int i=0; i<n; i++){
        cin >> rock[i];
        if(max_num<rock[i]) max_num=rock[i];
    }

    // **거쳐간 지점에 적혀있던 숫자들 중** 최댓값이 최소가 되도록 하는 프로그램을 작성
    int answer=101;
    for(int i=max(rock[0], rock[n-1]); i<=max_num; i++){
        //cout << "max_val=" << i << " " << IsPossible(i)<<'\n';
        if(IsPossible(i)) answer=min(answer, i);
    }
    cout << answer;
    return 0;
}