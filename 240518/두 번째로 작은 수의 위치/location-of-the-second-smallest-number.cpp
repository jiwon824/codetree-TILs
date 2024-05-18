#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int sorted_arr[101]={0, };
    for(int i=0; i<n; i++){
        sorted_arr[i]=arr[i];
    }

    // 정렬 후 2번째로 작은 수가 몇 개인지 확인
    sort(sorted_arr, sorted_arr+n);
    int answer = -1, min_num=sorted_arr[0], min_num2=101;
    for(int i =0; i<n; i++){
        if(sorted_arr[i]>min_num){
            min_num2=sorted_arr[i];

            // min_num2와 같은 수가 있는 경우 -1 출력 후 프로그램 종료
            if(i!=n-1 && sorted_arr[i]==sorted_arr[i+1]){
                cout << answer;
                return 0;
            }
            break;
        }
    }

    // 2번째로 작은 수가 없는 경우 -1출력
    if(min_num2==101) cout << answer;
    else{
        // 원본 배열에서 2번째로 작은 수의 idx 찾기
        for(int i=0; i<n; i++){
            if(arr[i]==min_num2) {
                cout << i+1;
                break;
            }
        }
    }

    return 0;
}