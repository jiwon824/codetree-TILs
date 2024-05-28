#include <iostream>

using namespace std;

int arr[101][101];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int answer=0;
    // 가로 체크
    for(int i=0; i<n; i++){
        int cnt =1;
        for(int j=1; j<n; j++){
            if(arr[i][j-1]==arr[i][j]) cnt++;
            else cnt=1;
            if(cnt>=m){
                answer++;
                break;
            }
        }
    }
    
    // 세로 체크
    for(int i=0; i<n; i++){
        int cnt=1;
        for(int j=1; j<n; j++){
            if(arr[j-1][i]==arr[j][i]) cnt++;
            else cnt=1;
            if(cnt>=m){
                answer++;
                break;
            }
        }
    }
    cout << answer<<'\n';
    return 0;
}