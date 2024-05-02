#include <iostream>

using namespace std;

int arr[101];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    

    // i번째 인덱스부터 시작
    int answer =0;
    for(int i=0; i<n; i++){
        int sum=0, tmp_m=m, idx=i;
        // m번 움직임을 반복
        //cout << i <<"번째에서 시작\n";
        while(tmp_m--){
            sum+=arr[idx];
            idx=arr[idx]-1;
            //cout << sum <<'\n';
        }
        //cout << i << " " << sum <<'\n';
        if(answer<sum) answer = sum;
    }

    cout << answer;
    return 0;
}