#include <iostream>

using namespace std;

// 좌상(-1, -1) 상(-1, 0) 우상(-1, 1)
// 좌(0, -1)             우(0, 1)
// 좌하(1, -1)  하(1, 0)  우하(1, 1) 
int dx[8] ={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] ={-1, 0, 1, 1, 1, 0, -1, -1};


int main() {
    int n, m;
    cin >> n >> m;
    string *s = new string[m];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            // LEE를 찾아야 하므로 L을 발견하면 탐색 시작
            if(s[i][j]=='L'){
                // 8방향 탐색
                for(int k=0;k<8; k++){
                    string tmp = "L";
                    int x=i, y=j;
                    // LEE는 3글자니까 3개만 보면 됨
                    for(int l=0; l<3;l++){
                        int nx =x+dx[k];
                        int ny =y+dy[k];
                        //다음에 탐색할 좌표가 점위를 벗어나면 break
                        if(nx<0|| nx>=n || ny<0 || ny>=m) break;
                        if(s[nx][ny]=='E'){
                            x=nx;
                            y=ny;
                            tmp=tmp+'E';
                        }
                    }
                    if(tmp=="LEE") answer++;
                }
            }

        } // for j
    } //for i

    cout << answer;
    return 0;
}