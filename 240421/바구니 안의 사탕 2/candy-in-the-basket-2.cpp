#include <iostream>

using namespace std;

int arr[101]; // 바구니
int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        // 한 줄에 하나씩 각 사탕의 개수와 바구니의 좌표가 공백을 사이에 두고 주어집니다. 
        int pos, candy;
        cin >> candy >> pos;
        arr[pos] += candy; // 같은 위치에 바구니 여러 개 놓는 것이 가능해서 +=
    }

    int c = k, max_candy=0;
    for(int i=0; i<101; i++){
        int num_of_candy =0;
        for(int j =i-k; j<=i+k; j++){
            if(j<0 || j>=101) break;
            num_of_candy += arr[j];
            //cout << num_of_candy <<'\n';
        }

        if(max_candy < num_of_candy){
            max_candy = num_of_candy;
            c=i;
        }
    }

    cout << max_candy;
    return 0;
}