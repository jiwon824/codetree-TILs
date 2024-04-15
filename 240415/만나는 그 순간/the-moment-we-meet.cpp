#include <iostream>

#define MAX_MOVE 1000001 // 1000*1000

using namespace std;

int a[MAX_MOVE];
int b[MAX_MOVE];


int main() {
    int n, m;
    // 첫 번째 줄에 N과 M이 주어집니다.
    cin >> n >> m;
    int aTime=1, bTime=1;
    // N개의 줄에 걸쳐 각 줄마다 A가 어떤 방향으로 몇 초 동안 이동했는지
    for(int i=0; i<n; i++){
        char dir;
        int t;
        cin >> dir >> t;
        
        if(dir=='L') {
            while (t--){
                a[aTime] =a[aTime-1]-1;
                aTime++;
            }
        }
        else {
            while (t--){
                a[aTime] =a[aTime-1]+1;
                aTime++;
            }
        }
        
    }

    // M개의 줄에 걸쳐 각 줄마다 B가 어떤 방향으로 몇 초 동안 이동했는지
    for(int i=0; i<m; i++){
        char dir;
        int t;
        cin >> dir >> t;

        if(dir=='L') {
            while (t--){
                b[bTime] =b[bTime-1]-1;
                bTime++;
            }
        }
        else {
            while (t--){
                b[bTime] =b[bTime-1]+1;
                bTime++;
            }
        }
    }
    
    bool exist = false;
    for(int i=1;i<aTime;i++){
        //cout << b[i] << " ";
        if (a[i]==b[i]){
            exist = true;
            cout << i;
            break;
        }
    }
    if(!exist) cout << "-1";
    return 0;
}