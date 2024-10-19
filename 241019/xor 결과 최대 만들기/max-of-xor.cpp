#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;

int n, m, answer;
int arr[MAX_N+1];
vector<int> nums;

void calculateXor(){
    int result=nums[0];
    for(int i=1; i<m; ++i){
        result^=nums[i];
    }
    answer=max(answer, result);
}

void choose(int curr, int cnt){
    if(curr==n){
        if(cnt==m) calculateXor();
        return;
    }

    nums.push_back(arr[curr]);
    choose(curr+1, cnt+1);

    nums.pop_back();
    choose(curr+1, cnt);
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    choose(0, 0);
    
    cout << answer << '\n';
    return 0;
}