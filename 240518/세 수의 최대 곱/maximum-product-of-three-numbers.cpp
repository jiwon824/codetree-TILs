#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
    // case1. 가장 큰 양수를 3개 뽑는 경우
    // case2. 가장 작은 음수 2개와 가장 큰 양수 1개를 뽑는 경우
    // case3. (주어진 수<=0) 인 경우 정답=0
    // case4. 음수만 주어진 경우 절대값이 가장 작은 음수 3개를 뽑아야 함
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int answer =0;
    // 가장 큰 수가 음수인 경우==음수만 주어진 경우
    if(arr[n-1]<0) answer = arr[n-1] * arr[n-2] * arr[n-3];
    else if(arr[n-1]==0) answer=0;
    else{
        int case1 = arr[n-1] * arr[n-2] * arr[n-3];
        int case2 = arr[0] * arr[1] * arr[n-1];
        answer = max(case1, case2);
    }

    cout << answer;
    return 0;
}