#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<2*n;i++){
        cin >> arr[i];
    }

    // 2개의 원소가 하나의 그룹을 이루도록 하여 총 n개의 그룹 만들기
    // 그룹 내 수의 차이 중 가장 작은 값 구하기
    // 구한 값 중 가장 큰 값을 출력
        // 15 2 7 9 10 5를 정렬하면 2 5 7 9 10 15
        // 정렬한 값을 (arr[2n-1], arr[n-1]) 이렇게 짝지어주기
    sort(arr, arr+2*n);
    
    int answer=1000000000;
    for(int i=0; i<n; i++){
        int diff = arr[i+n]-arr[i];
        if(diff<answer) answer = diff;
    }
    cout << answer;
    return 0;
}