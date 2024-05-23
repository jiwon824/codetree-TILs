#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<pair<int, int>> line;

int Make_Line_Contain_All_of_line(int exclude_line){
    int min_x=100, max_x=1;
    for(int i=0; i<n; i++){
        if (i==exclude_line) continue;
        
        if(line[i].first<min_x) min_x = line[i].first;
        if(line[i].second>max_x) max_x = line[i].second;
    }
    return max_x-min_x;
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        line.push_back({x1, x2});
    }

    //i번째 선분을 제거했을 때 n-1개의 선분을 모두 포함하는 선분의 길
    int answer =INT_MAX;
    for(int i=0; i<n; i++){
        int length = Make_Line_Contain_All_of_line(i);
        if(length<answer) answer = length;
    }
    cout << answer;
    return 0;
}