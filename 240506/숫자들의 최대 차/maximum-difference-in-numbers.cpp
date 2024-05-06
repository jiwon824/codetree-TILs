#include <iostream>

using namespace std;
int n, k;
int arr[1001];


int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];        
    }
    
    int answer =0;
    // i가 최솟값인 경우 뽑을 수 있는 숫자의 갯수
    for(int i=0;i<n;i++){
        int cnt=1;
        for(int j=i+1; j<n; j++){
            if(arr[j]-arr[i]>=0 && arr[j]-arr[i]<=k) {
                //cout << arr[i] << " "<< arr[j] << " " << arr[j]-arr[i]<<'\n';
                cnt++;
            }

        }
        if(answer<cnt) answer =cnt;
    }
    cout << answer;

    return 0;
}