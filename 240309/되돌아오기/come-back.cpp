#include <iostream>

using namespace std;

// 상(-1, 0) 하(1, 0) 좌(0, -1) 우(0, 1)
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int ToIntDir(char c){
    switch(c){
        case 'N':
            return 0;
        case 'S':
            return 1;
        case 'W':
            return 2;
        case 'E':
            return 3;
        default:
            break;  
    }
}
int main() {
    int n;
    cin >>n;

    int x=0, y=0, time=0;
    for (int i=0;i<n;i++){
        char dir;
        int movement;
        cin >> dir >> movement;
        int iDir =ToIntDir(dir);
        for (int j=0;j<movement;j++){
            int nx = x +dx[iDir];
            int ny = y +dy[iDir];
            x=nx;
            y=ny;
            time++;
            if(x==0&&y==0){
                cout << time;
                return 0;
            }
        }
    }
    
    cout << "-1";
    return 0;
}