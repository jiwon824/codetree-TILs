#include <iostream>

using namespace std;

int arr[101];

// 1 2 4 3 -> 2 4 1 3 -> 1 2 3 4
// 8 1 5 2 6 4 7 3
// 1 5 2 6 4 7 3 8
// 5 2 6 4 7 3 1 8
// 2 6 4 7 3 1 5 8  // 맨 뒤에부터 봐서 내림차순이 끊기면 앞에는 전부 재정렬되어야 함
// 6 4 7 3 1 2 5 8
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int sort_cnt=1;
    for(int i=n-1; i>0; i--){
        if(arr[i-1]<arr[i]) sort_cnt++;
        else break;
    }
    cout << n-sort_cnt;
    
    return 0;
}