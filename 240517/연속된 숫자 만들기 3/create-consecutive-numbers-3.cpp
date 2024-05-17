#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    // 연속된 수가 되기 위한 최대 이동 횟수
    sort(arr, arr+3);
    if(arr[0]+1==arr[1] && arr[1]+1==arr[2]) cout <<0;
    // 1 3 4
    else{
        // 156 -> 145 -> 134 -> 123 == 1과 5사이의 숫자 234 3개 (5-1-1)
        int answer = max(arr[1]-arr[0], arr[2]-arr[1]);
        cout << answer-1;
    }
    return 0;
}