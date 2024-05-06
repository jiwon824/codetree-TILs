#include <iostream>

using namespace std;

int n;
int num_range[11][2];

bool Solution(int x){
    for(int i=0; i<n; i++){
        x *=2;
        if(x<num_range[i][0] || x>num_range[i][1]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num_range[i][0] >> num_range[i][1];
    }

    // 조건을 만족하는 수 중 최소값
    int answer =10000;
    for(int i=1; i<num_range[n-1][1]; i++){
        if(Solution(i)){
            if(i<answer) {
                answer=i;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}