#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_POS 1000

using namespace std;

int n;
vector<pair<int,int> > points;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second > b.second;
}

int CntPoint(int midX, int midY){
    // [0][0]:2 [0][1]:1, [1][0]:3, [1][1]:4
    int quadrant[2][2]={0, };
    for(const auto& e: points){
        // x=i, y=j일 때 점들이 어느 사분면에 속하는지 나누기
        if(e.first<midX){
            if(e.second>midY) quadrant[0][0]++;
            else quadrant[1][0]++;
        }
        else{
            if(e.second>midY) quadrant[0][1]++;
            else quadrant[1][1]++;
        } 
    }

    // 4개의 사분면 중 가장 점이 많은 사분면의 점개수
    int numOfPoints=0;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            numOfPoints = max(numOfPoints, quadrant[i][j]);
        }
    }

    return numOfPoints;
}

int main() {
    // input
    cin >> n;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    
    // 정렬해서 중위값에 선을 그으면 안 되나?
    sort(points.begin(), points.end());
    int midX = points[n/2].first;
    sort(points.begin(), points.end(), cmp);
    int midY = points[n/2].second;
    

    int answer=2e9;
    for(int i=midX-1; i<=midX+1; ++i){
        if(i==midX) continue;
        for(int j=midY-1; j<=midY+1; ++j){
            if(j==midY) continue;
            int numOfPoints=CntPoint(i, j);    
            answer = min(answer, numOfPoints);
        }
    }

    // output
    cout << answer << '\n';

    return 0;
}