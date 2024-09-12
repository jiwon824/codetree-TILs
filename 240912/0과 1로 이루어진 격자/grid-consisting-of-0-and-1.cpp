#include <iostream>
using namespace std;

const int MAX_N =11;

int n;
string arr[MAX_N];

void Reversing(int x, int y){
    for(int i=0; i<=x; ++i){
        for(int j=0; j<=y; ++j){
            if(arr[i][j]=='1') arr[i][j]='0';
            else arr[i][j]='1';
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    
    // 모든 칸을 0으로 만들려고 할 때, 칸을 누르는 횟수를 최소화하는 프로그램을 작성
    int answer=0;
    for(int i=n-1; i>=0; --i){
        for(int j=n-1; j>=0; --j){
            if(arr[i][j]=='1'){
                Reversing(i, j);
                answer++;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}