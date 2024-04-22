#include <iostream>

using namespace std;

int arr[10][10];
int main() {
    int n;
    cin >> n;

    int cnt=1;

    // [0][0] [0][1] [0][2]
    // [1][0] [1][1] [1][2]
    // [2][0] [2][1] [2][2]
    for(int i=1; i<=n; i++){
        if(i%2!=0){
            for(int j=1; j<=n; j++){
                arr[n-j][n-i] =cnt;
                cnt++;
            }
        }
        else{
            for(int j=0; j<n; j++){
                arr[j][n-i] = cnt;
                cnt++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] <<" ";
        }
        cout <<'\n';
    }
    return 0;
}