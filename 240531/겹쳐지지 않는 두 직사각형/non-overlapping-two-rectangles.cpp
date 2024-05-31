#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int answer=INT_MIN;
int arr[6][6];

int FindSum(int startX, int endX, int startY, int endY){
    int sum =0;
    for(int i=startX; i<=endX; i++){
        for(int j= startY; j<=endY; j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

// 겹치지 않게 너비와 높이 정하기
void SelectRectangle(int r1X, int r1Y, int r2X, int r2Y){
    // 사각형1의 너비와 높이 r1W, r1H
    for(int r1H=r1X; r1H<n; r1H++){
        for(int r1W=r1Y; r1W<m; r1W++){
            // 사각형2의 너비와 높이 r2W, r2H
            for(int r2H=r2X; r2H<n; r2H++){
                for(int r2W=r2Y; r2W<m; r2W++){
                    // 겹치지 않는 경우에만 검사해야 한다
                    if(r1H<r2X || r2H<r1X || r1W<r2Y || r2W<r1Y){
                        int r1Sum = FindSum(r1X, r1H, r1Y, r1W);
                        int r2Sum = FindSum(r2X, r2H, r2Y, r2W);
                        answer = max(answer, r1Sum+r2Sum);
                    }

                }
            }
        }
    }
}

// 겹치지 않게 점 고르기
void PickPoint(){
    // (i, j)점에서 시작하는 사각형1
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // (k, l) 점에서 시작하는 사각형2
            for(int k=i; k<n; k++){
                for(int l=0; l<m; l++){
                    // 겹치는 점을 골랐다면 검사하지 않음
                    if(i==k && j==l) continue;
                    SelectRectangle(i, j, k, l);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    PickPoint();
    cout << answer <<'\n';

    return 0;
}