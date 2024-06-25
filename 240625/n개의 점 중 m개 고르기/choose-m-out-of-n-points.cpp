#include <iostream>
#include <vector>
#include<climits>
#include <cmath> //pow
#include <tuple> //tie
using namespace std;

int n, m, answer=INT_MAX;
vector<pair<int,int> > point;
vector<pair<int,int> > selected;
bool visited[21] = {false, };

int FindMaxDist(){
    int maxDist=0;
    for(size_t i=0; i<selected.size(); ++i){
        for(size_t j=i+1; j<selected.size(); ++j){
            int x1, y1, x2, y2;
            tie(x1, y1) = selected[i];
            tie(x2, y2) = selected[j];
            // 두점 사이의 거리(출력할 때 제곱해야 하니까 sqrt 생략)
            int dist = pow(x1-x2, 2)+pow(y1-y2, 2);
            maxDist=max(maxDist, dist);
        }
    }
    return maxDist;
}

void Choose(int idx, int numOfChosen){
    // 종료 조건
    if(numOfChosen==m){
        answer = min(answer, FindMaxDist());
        return;
    }

    // 재귀 호출
    for(size_t i=idx; i<point.size(); ++i){
        if(visited[i]) continue;
        
        selected.push_back(point[i]);
        visited[i]=true;
        Choose(i+1, numOfChosen+1);

        selected.pop_back();
        visited[i]=false;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }

    Choose(0, 0);

    cout << answer <<'\n';
    return 0;
}