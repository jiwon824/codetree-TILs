#include <iostream>
#include <algorithm>
#define OFFSET 1000

using namespace std;
int arr[OFFSET*2+1][OFFSET*2+1];

void Check(int cnt, int x1, int y1, int x2, int y2){
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            arr[i][j]=cnt;
        }
    }
}

int main() {
    
    for(int i=0;i<2;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=OFFSET;
        y1+=OFFSET;
        x2+=OFFSET;
        y2+=OFFSET;
        Check(i+1, x1, y1, x2, y2);
    }

    int r1=OFFSET*2+1, c1=OFFSET*2+1, r2=0, c2=0;
    for(int i=0; i<OFFSET*2+1; i++){
        for(int j=0; j<OFFSET*2+1; j++){
            if(arr[i][j]==1){
                // 좌측하단(r1, c1) 우측상단?(r2, c2)구하기
                r1 = min(r1, i);
                c1 = min(c1, j);
                r2 = max(r2, i);
                c2 = max(c2, j);
            }
        }
    }
    int width = r2-r1+1;
    int height = c2-c1+1;
    cout <<width*height;
    return 0;
}