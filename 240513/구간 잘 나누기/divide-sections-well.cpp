#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[101];
int n, m;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int answer = INT_MAX;
    // 구간 합의 최댓값이 i일 경우
    // 주어지는 숫자는 1이상 100이하, 최대 100개의 수가 주어지니까
    for(int i=1; i<=10000; i++){
        bool isAnswer = true;
        int section =1;
        int interval_sum = 0; //현재 구간합
        for(int j=0; j<n; j++){
            if(arr[j]>i){
                isAnswer = false;
                break;
            }

            if(interval_sum+arr[j]>i){
                interval_sum = 0;
                section++;
            }
            interval_sum+=arr[j];
        }
        if(isAnswer && section<=m){
            if(i<answer) answer=i;
        }
    }
    cout << answer;
    
    return 0;
}