#include <iostream>
#define OFFSET 100

using namespace std;
int arr[2*OFFSET+1][2*OFFSET+1];
void Check(int color, int x1, int y1, int x2, int y2){
    for(int i=x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            arr[i][j]=color;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int color = 1; // 홀수:red, 짝수:blue
    for (int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=OFFSET;
        y1+=OFFSET;
        x2+=OFFSET;
        y2+=OFFSET;
        Check(color, x1, y1, x2, y2);
        color++;
    }

    int answer =0;
    for(int i=0; i<2*OFFSET+1; i++){
        for(int j=0; j<2*OFFSET+1; j++){
            if(arr[i][j]!=0 && arr[i][j]%2==0) answer++;
        }
    }
    cout << answer;
    return 0;
}