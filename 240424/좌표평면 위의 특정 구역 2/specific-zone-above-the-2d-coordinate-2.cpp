#include <iostream>
#include <climits>

using namespace std;

int coordinate[100][100];
int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> coordinate[i][0] >> coordinate[i][1];
    }
    
    int answer = INT_MAX;
    for(int i=0; i<n; i++){
        int max_x = 0, max_y =0, min_x=40000, min_y=40000;
        for(int j=0; j<n; j++){
            if(i==j) continue; // i 점을 제외하고 min, max값을 구한다

            int x = coordinate[j][0], y=coordinate[j][1];
            //cout << x <<" " << y <<'\n';
            if(x<min_x) min_x = x;
            if(x>max_x) max_x = x;

            if(y<min_y) min_y = y;
            if (y>max_y) max_y = y;
        }

        int width = (max_x-min_x) * (max_y-min_y);
        //cout << max_x <<" " << min_x << " " << max_y << " " << min_y<< "  " << width <<'\n';
        if(width<answer) answer=width;
    }
    cout << answer;
    return 0;
}