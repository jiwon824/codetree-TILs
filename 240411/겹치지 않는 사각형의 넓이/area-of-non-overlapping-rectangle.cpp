#include <iostream>

using namespace std;
int arr[2001][2001];

void Check(int cnt, int x1, int y1, int x2, int y2){
    for(int i=x1; i<x2;i++){
        for(int j=y1; j<y2; j++){
            arr[i][j] = cnt;
        }
    }
}
int main() {
    for (int i=0; i<3; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=1000;
        y1+=1000;
        x2+=1000;
        y2+=1000;
        Check(i+1, x1, y1, x2, y2);
    }

    int answer=0;
    for (int i=0; i<2001; i++){
        for (int j=0; j<2001; j++){
            if(arr[i][j]==1 || arr[i][j]==2) answer++;
        }
    }
    cout << answer;
    return 0;
}