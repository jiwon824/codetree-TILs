#include <iostream>

using namespace std;

int lines[101][2];
bool isCross(int a, int b){
    int x1 = lines[a][0], y1 =0, x2=lines[a][1], y2=1; // line1
    int x3 = lines[b][0], y3 =0, x4=lines[b][1], y4=1; // line2
    if(x1<x3 && x4<x2) return true;
    if(x3<x1 && x2<x4) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        // N개의 줄에 걸쳐 각 줄마다 x1과 x2
        // 해당 선분의 끝점이 (x1, 0), (x2, 1)임을 의미
        cin >> lines[i][0] >> lines[i][1];
    }

    // 겹치는 선분 판별법: [i][x1]<[j][x1] &&[i][x2]>[j][x2] << 아니면 직선의 방정식에 대입해야 할 것 같기도 하고?
    // 직선의 
    int answer =0;
    for(int i=0; i<n; i++){
        bool cross =false;
        for(int j =0; j<n; j++){
            if(i==j) continue; // 같은 점이라면 판단x

            // i의 직선의 방정식, j의 직선의 방정식을 구하기
            cross = isCross(i, j);
            if(cross) break;
            // cout << "(" << lines[i][0] << ", " << lines[i][1] << ") (" << lines[j][0] <<  ", "<< lines[j][1] <<")\n";
            //if(cross) cout << "true\n";
            //else cout << "false\n";
        }
        if (!cross) answer++;
        ///cout << answer<<'\n';
        //cout << "==========================\n";
    }


    cout << answer;
    return 0;
}