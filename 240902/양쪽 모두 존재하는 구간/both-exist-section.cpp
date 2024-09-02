#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 1000001;

int n, m;
int num[MAX_N];

// 구간 내에서도, 구간 밖에서도 모두 1이상 m이하의 숫자가 적어도 하나씩 존재하도록 하는 구간 중 가장 짧은 구간의 길이
// 단, 그런 구간이 없을 경우 -1을 출력
int Solution(){
    unordered_map<int,int> inside;
    unordered_map<int,int> outside;

    // 1. 처음에는 모든 원소가 구간 밖에 존재
    for(int i=0; i<n; ++i){
        outside[num[i]]++;
    }

    int min_len=2e9;
    int right=0;
    for(int left=0; left<n; ++left){
        while(right<n && inside.size()<m){
            // num[right]를 구역 안으로 넣는다
            outside[num[right]]--;
            inside[num[right]]++;
            // size로 m개를 판단하므로 0이면 map에서 삭제
            if(outside[num[right]]==0) outside.erase(num[right]);
            right++;
        }

        if(inside.size()==m && outside.size()==m){
            min_len = min(min_len, right-left);
        }

        // num[left]를 구역 바깥으로 뺀다.
        inside[num[left]]--;        
        outside[num[left]]++;
        // size로 m개를 판단하므로 0이면 map에서 삭제
        if(inside[num[left]]==0) inside.erase(num[left]);
    }


    if(min_len==2e9) return -1;
    else return min_len;
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    cout << Solution() << '\n';    
    return 0;
}