#include <iostream>

using namespace std;

int n, answer;
int map[21][21];

bool InRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

// 사각형 검사
int InspectingRectangles(int x, int y, int width, int height){
    // 우상(-1, 1) 좌상(-1, -1) 좌하(1, -1) 우하(1, 1)
    int dx[4] ={-1, -1, 1, 1};
    int dy[4] ={1, -1, -1, 1};

    int sum =0;
    for(int dir=0; dir<4; dir++){
        if(dir%2==0){ // dir방향으로 width만큼 이동
            for(int w=0; w<width; w++){
                x=x+dx[dir];
                y=y+dy[dir];
                if (!InRange(x, y)) return 0;
                sum += map[x][y];
            }
        }
        else{ // dir방향으로 height만큼 이동
            for(int h=0; h<height; h++){
                x=x+dx[dir];
                y=y+dy[dir];
                if (!InRange(x, y)) return 0;
                sum += map[x][y];
            }
        }
    }
    return sum;
}

void PointToInspect(){
    //최소 (2,1) 점은 되어야 1, 2, 3, 4 방향대로 순회할 수 있음
    for(int i=2; i<n; i++){
        for(int j=1; j<n-1; j++){
            // w는 1, 3길이 / h는 2, 4길이
            for(int w=1; w<n-1; w++){
                for(int h=1; h<n-1; h++){
                    answer = max(answer, InspectingRectangles(i, j, w, h));
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    PointToInspect();
    cout << answer <<'\n';

    return 0;
}