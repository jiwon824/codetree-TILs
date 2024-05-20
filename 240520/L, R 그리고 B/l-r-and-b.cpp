#include <iostream>

using namespace std;


string s[11];

int main() {
    for(int i=0; i<10; i++){
        cin>> s[i];
    }
    int l_x, l_y, b_x, b_y, r_x, r_y;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(s[i][j]=='B'){
                b_x =i;
                b_y=j;
            }
            else if(s[i][j]=='L'){
                l_x =i;
                l_y=j;
            }
            else if(s[i][j]=='R'){
                r_x = i;
                r_y = j;
            }
        }
    }
    int answer = abs(l_x-b_x)+abs(l_y-b_y)-1;
    if((l_x==b_x && l_x==r_x) || (l_y==b_y && l_y==r_y)) answer+=2;
    cout << answer;
    return 0;
}