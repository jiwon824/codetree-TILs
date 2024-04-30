#include <iostream>

using namespace std;

int yabawi[100][3];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        yabawi[i][0] = a-1;
        yabawi[i][1] = b-1;
        yabawi[i][2] = c-1;
    }

    int answer=0;
    //i번째 종이컵에 돌을 넣음
    for(int i=0; i<3; i++){
        int num_of_win=0; // 이긴 횟수
        int cup[3]={0, }; // 컵
        cup[i]=1; // i번째 컵에 조약돌 넣기
        for(int j=0; j<n; j++){
            // a번째 종이컵과 b번째 종이컵을 교환 후 c번 종이컵 확인
            int a = yabawi[j][0], b = yabawi[j][1], c = yabawi[j][2];
            // 교환
            int tmp = cup[a];
            cup[a]=cup[b];
            cup[b]= tmp;
            if(cup[c]==1) num_of_win++;
        }

        if(answer<num_of_win) answer=num_of_win;
    }
    cout << answer;
    return 0;
}