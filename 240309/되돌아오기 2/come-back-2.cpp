#include <iostream>
#include <string>

using namespace std;

// 상(-1, 0) 우(0, 1) 하(1, 0) 좌(0, -1)
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int main() {
    string command;
    cin >> command;
    int x=0, y=0, dir =0, time=0;
    for (auto e: command){
        if (e=='F'){
            x=x+dx[dir];
            y=y+dy[dir];
        }else if(e == 'L'){
            dir=(dir+3)%4;
        }
        else{
            dir=(dir+1)%4;
        }
        time++;
        if(x==0&&y==0){
            cout << time;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}