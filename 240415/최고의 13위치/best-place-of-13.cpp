#include <iostream>

using namespace std;

int arr[21][21];
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int answer=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n-2;j++){
            answer = max(answer, arr[i][j]+arr[i][j+1]+arr[i][j+2]);
        }
    }
    cout << answer;
    return 0;
}