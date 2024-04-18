#include <iostream>

using namespace std;

//서로 다른 3개의 숫자를 골랐을 때
// 1. carry가 전혀 발생하지 않으면서
// 2. 나올 수 있는 숫자 합의 최댓값을 계산
int main() {
    int n;
    cin >> n;
    int *arr= new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 서로 다른 3개의 숫자 고르기
    int answer =-1;
    for(int i=0; i<n-2; i++){
        for(int j =i+1; j<n-1;j++){
            for(int k=j+1; k<n;k++){
                bool exist_carry = false;
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];

                // 세 숫자가 모두 0이 될 때까지 반복
                while(true){
                    if(a==0 && b==0 && c==0) break;

                    if(a%10 + b%10 + c%10 >=10){
                        exist_carry =true;
                        break;
                    }
                    else{
                        a/=10;
                        b/=10;
                        c/=10;
                    }
                }
                // carry가 발생하지 않았으면 3개 숫자의 합을 구해서 최대값 갱신
                if(!exist_carry){
                    if(answer < arr[i]+arr[j]+arr[k]) answer= arr[i]+arr[j]+arr[k];
                }

            } // for k
        } // for j
    } // for i
    // 모든 숫자쌍에서 carry가 발생할 경우, -1을 출력
    cout << answer;
    return 0;
}