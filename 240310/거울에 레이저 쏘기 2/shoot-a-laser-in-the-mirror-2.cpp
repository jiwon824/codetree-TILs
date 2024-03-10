#include <iostream>

using namespace std;

//하(1, 0) 좌(0, -1) 상(-1, 0) 우(0, 1)
int dx[4]={1, 0, -1, 0}, dy[4]={0, -1, 0, 1};
char** map;

// 시작위치 구하기
int* FindStartPos(int k, int n){
    int* pos =new int[2];
    int dir =3;
    int x=0, y=0, time=0;
    while (k!=time){
        int nx =x+dx[dir];
        int ny =y+dy[dir];
        // 벽에 부딪히면 시계방향으로 돌아야 한다.
        if(nx<0 || ny<0 || nx>=n || ny>=n){
            dir=(dir+1)%4;
        }else{
            x=nx;
            y=ny;
        }
        time++;
    }
    pos[0]=x, pos[1]=y;
    return pos;
}

int Reflect(int k, int n){
    // dir = n으로 나눠서 0:하, 1:좌, 2:상, 3:우
    int dir =k/n;
    int* startpos = FindStartPos(k, n);
    int nx =startpos[0], ny=startpos[1];
    int cnt=0;
    // map을 벗어날 때까지 반복
    // [0]하 [1]좌 [2]상 [3]우
    while(nx>=0 && ny>=0 && nx<n && ny<n){
        //cout <<"map[nx][ny]: " << map[nx][ny] << ", nx: "<< nx << ", ny: "<<ny<<", dir: "<< dir<< ", cnt: "<<cnt<<"\n";
        if(map[nx][ny]=='/'){
            // '/'의 경우
            if(dir==1 || dir==3){
                // 반시계 회전(좌[1]->하[0], 우[3]->상[2])
                dir=(dir+3)%4;
            }else{
                // 시계방향 회전(하[0]->좌[1], 상[2]->우[3])
                dir=(dir+1)%4;
            }
        }else{
            // '\'의 경우
            if(dir==0 || dir==2){
                // 반시계방향 회전(하[0]->우[3], 상[2]->좌[1])
                dir=(dir+3)%4;
            }else{
                // 시계 회전(좌[1]->상[2], 우[3]->하[0])
                dir=(dir+1)%4;
            }
        }
        cnt++;
        nx+=dx[dir];
        ny+=dy[dir];
    }
    
    return cnt;
}

int main() {
    int n;
    cin >> n;

    //n*n map 만들기
    map = new char*[n];
    for(int i=0;i<n;i++){
        map[i]= new char[n];
    }

    //map 정보 입력
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >>map[i][j];
        }
    }

    int k;
    cin >> k;
    cout << Reflect(k-1, n);
    return 0;
}