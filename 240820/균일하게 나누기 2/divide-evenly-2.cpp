#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_POS 1001
using namespace std;

int n;
vector<pair<int, int>> points;
int prefixSum[MAX_POS][MAX_POS];

void makePrefixSum(){
    // points 좌표 체크
    for (const auto& p : points) {
        prefixSum[p.first][p.second]++;
    }

    // prefixSum 배열 채우기
    for (int i=1; i<MAX_POS; ++i) {
        for (int j=1; j<MAX_POS; ++j) {
            prefixSum[i][j] += prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
}

int getPointsInRegion(int x1, int y1, int x2, int y2) {
    return prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    // prefixSum 배열 채우기
    makePrefixSum();
    
    int minMaxPoints = 2e9; // int max
    // x, y는 짝수이므로 2씩 더해줌
    for (int x=2; x<MAX_POS; x+=2) {
        for (int y=2; y<MAX_POS; y+=2) {

            int q1 = getPointsInRegion(1, y+1, x-1, MAX_POS-1);
            int q2 = getPointsInRegion(x, y+1, MAX_POS-1, MAX_POS-1);
            int q3 = getPointsInRegion(1, 1, x-1, y);
            int q4 = getPointsInRegion(x, 1, MAX_POS-1, y);

            //C++11부터 이렇게 쓸 수 있어짐
            int maxQuadrant = max({q1, q2, q3, q4});
            minMaxPoints = min(minMaxPoints, maxQuadrant);
        }
    }

    cout << minMaxPoints << '\n';

    return 0;
}