#include <iostream>
#include <algorithm>

using namespace std;


int coordinates[101][2];
int main() {
    int n;
    cin >> n;
    int max_x=0, max_y=0;
    for(int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
        if(max_x<coordinates[i][0])max_x=coordinates[i][0];
        if(max_y<coordinates[i][1])max_y=coordinates[i][1];
    }
    
    int min_m = 100; // 점 갯수는 최대 100개니까
    // x, y는 모두 홀수이기 때문에 짝수지점에만 x, y축을 그려보면 된다.
    for(int i=0; i<=max_x; i+=2){
        for(int j=0; j<=max_y; j+=2){
            // x=i, y=j일 때 모든 점 탐색
            int q1=0, q2=0, q3=0, q4=0;
            for(int k=0; k<n; k++){
                if(i<coordinates[k][0] && j<coordinates[k][1]) q1++;
                else if(i>coordinates[k][0] && j<coordinates[k][1]) q2++;
                else if(i>coordinates[k][0] && j>coordinates[k][1]) q3++;
                else if(i<coordinates[k][0] && j>coordinates[k][1]) q4++;
            }
            int q_max = max(max(q1, q2), max(q3, q4));
            if(q_max<min_m) min_m = q_max;
        }
    }

    cout << min_m;
    return 0;
}