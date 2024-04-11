#include <iostream>

using namespace std;

int arr[201][201];
void Check(int x1, int y1, int x2, int y2){
    //cout << "Check\n";
    for (int i=x1; i<x2;i++){
        for(int j=y1;j<y2;j++){
            arr[i][j]=1;
            //cout << i << " "<< j <<'\n';
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Check(x1, y1, x2, y2);
    }
    
    // 넓이
    int answer =0;
    for(int i=0;i<201;i++){
        for(int j=0; j<201;j++){
            if(arr[i][j]==1) answer++;
        }
    }
    cout << answer;
    return 0;
}