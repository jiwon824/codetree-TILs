#include <iostream>

using namespace std;
int arr[201][201];
void Draw(int a, int b){
    for(int i=a;i<a+8;i++){
        for(int j=b;j<b+8;j++){
            arr[i][j]=1;
        }
    }
}
int main() {
    int n; // 가로세로 길이가 8이고 넓이가 64인 색종이 N장
    cin >> n;
    for(int i =0; i<n; i++){
        int x1, y1;
        cin >> x1 >> y1;
        x1+=100;
        y1+=100;
        Draw(x1, y1);
    }

    int answer =0;
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            if(arr[i][j]==1) answer++;
        }
    }
    cout << answer;
    return 0;
}