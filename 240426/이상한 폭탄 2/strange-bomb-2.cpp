#include <iostream>

using namespace std;
int arr[101];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int max_bomb_num = -1;
    for(int i=0; i<n; i++){
        // k범위 안에 같은 번호가 있으면 폭발한다.
        int bomb_num = -1;
        for(int j=i-k; j<=i+k; j++){
            // 배열 범위를 넘거나 자기자신을 건너뛴다
            if(j<0 || j>n || i==j) continue;
            
            if(arr[i]==arr[j]) bomb_num= arr[i];
        }

        if(max_bomb_num < bomb_num) max_bomb_num = bomb_num;
    }
    cout << max_bomb_num;
    return 0;
}