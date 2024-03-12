#include <iostream>
#include <string>

using namespace std;

// 상(-1, 0) 우(0, 1) 하(1, 0) 좌(0, -1)
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int** map;
int Solution(string s, int n){
    //가운데 위치에서 북쪽을 향한 상태로 시작
    int x=n/2, y=n/2, dir=0, answer=map[x][y];
    for (int i=0;i<s.length();i++){
        if(s[i]=='R'){
            dir =(dir+1)%4;
        }else if (s[i]=='L'){
            dir =(dir+3)%4;
        }else{
            int nx =x+dx[dir];
            int ny =y+dy[dir];
            if (nx<0 || ny<0 || nx>=n || ny >=n) continue;
            else{
                x=nx;
                y=ny;
                answer+=map[x][y];
            }
        }
        //cout <<"map[x][y]: " << map[x][y]<< ", answer: " << answer <<"\n";
    }
    return answer;
}

int main() {
    //n*n(n은 홀수), t는 s.length()
    int n, t;
    cin >> n >> t;
    string command;
    cin >> command;

    map =new int*[n];
    for(int i=0;i<n;i++){
        map[i]=new int[n];
    }
    
    //map 채우기
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }

    cout << Solution(command, n)<<'\n';    
    return 0;
}