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
    //cout << "findmaxdist\n";
    //for(size_t i=0; i<selected.size(); i++){
    //    cout <<selected[i].first << " " << selected[i].second<<'\n';
    //}
    for(size_t i=0; i<selected.size(); ++i){
        for(size_t j=i+1; j<selected.size(); ++j){
            int p1X, p1Y, p2X, p2Y;
            tie(p1X, p1Y) = selected[i];
            tie(p2X, p2Y) = selected[j];
            int dist = pow(p1X-p2X, 2)+pow(p1Y-p2Y, 2);
            maxDist=max(maxDist, dist);
        }
    }
    //cout << maxDist <<'\n';
    return maxDist;
}

void Choose(int numOfChosen){
    // 종료 조건
    if(numOfChosen==m){
        answer = min(answer, FindMaxDist());
        return;
    }

    // 재귀 호출
    for(size_t i=0; i<point.size(); ++i){
        if(visited[i]) continue;
        
        selected.push_back(point[i]);
        visited[i]=true;
        Choose(numOfChosen+1);

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

    Choose(0);

    cout << answer <<'\n';
    return 0;
}