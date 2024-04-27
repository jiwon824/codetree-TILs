#include <iostream>

using namespace std;

int lines[11][2]; // n개 (a,b)정보
int n;

bool isAnswer(int a, int b, int c){
    int arr[101]={0, };
    // arr에 i, j, k번째 선분들을 제외하고 체크함
    for(int i=0; i<n; i++){
        // i, j, k번째 선분은 제외시키니까
        if(i==a || i==b || i==c) continue;
        for(int j=lines[i][0]; j<=lines[i][1]; j++){
            arr[j]++;
        }
    }

    // 체크했는데 2이상인 수가 있으면 겹치는 것
    for(int i=0; i<101; i++){
        if(arr[i]>=2) return false;
    }
    return true;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> lines[i][0] >> lines[i][1];
    }

    int answer =0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                // 같은 선분이면 continue;
                if(i==j || j==k || i==k) continue;
                
                if(isAnswer(i, j, k)) answer++;
            }
        }
    }
    cout << answer;

    return 0;
}