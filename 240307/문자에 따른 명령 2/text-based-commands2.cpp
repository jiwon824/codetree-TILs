#include <iostream>
#include <string>

using namespace std;
// WSEN
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};


int main() {
    string s;
    cin >> s;
    int x=0, y=0;
    int dir = 3;
    for(int i =0; i<s.length();i++){
        if(s[i]=='L'){
            dir = (dir+3)%4;
        }else if (s[i]=='R'){
            dir =(dir+1)%4;
        }else{
            x+=dx[dir];
            y+=dy[dir];
        }
    }
    cout << x << " " << y;
    return 0;
}