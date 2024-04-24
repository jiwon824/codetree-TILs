#include <iostream>

using namespace std;

int coordinates[100][2];

int GetWidth(int p1, int p2, int p3){
    int x1 = coordinates[p1][0], y1=coordinates[p1][1];
    int x2 = coordinates[p2][0], y2=coordinates[p2][1];
    int x3 = coordinates[p3][0], y3=coordinates[p3][1];
    //cout << x1 << " " << y1 << " " <<  x2 << " " << y2 <<" " << x3 << " " << y3 <<'\n';
    // 한 변은 x축에 평행하며, 다른 한 변은 y축에 평행
    // x축에 평행= y값이 동일(0, 0)(1, 0) y축에 평행=x값이 동일(1, 2)(1, 0)
    if(y1!=y2 && y2!=y3 && y1!=y3) return -1;
    if(x1!=x2 && x2!=x3 && x1!=x3) return -1;

    //1/2 * (abs((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3))) 가 삼각형 넓이
    // 최대 넓이에 2를 곱한 값을 구하는 프로그램을 작성이니까 1/2없어도 
    return abs((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3));
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
    }

    int max_width =0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            for(int k=j+1; k<n; k++){
                // 같은 점이면 체크하지 않도록
                if(i==j || j==k || i==k) continue;

                int width = GetWidth(i, j, k);
                // GetWidth()의 결과가 -1이면 조건이 안 맞은 것
                //cout << width <<'\n';
                if(width!=-1) max_width = max(width, max_width);
            }
        }
    }
    cout << max_width;
    return 0;
}