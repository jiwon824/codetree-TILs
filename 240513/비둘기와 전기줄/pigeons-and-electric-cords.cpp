#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int dulgi, dir;
        cin >> dulgi >> dir;
        v.push_back({dulgi, dir});
    }

    // 조건이 같을 시 들어온 순서를 유지
    stable_sort(v.begin(), v.end(), cmp);

    //for(int i =0; i<v.size(); i++){
    //    for(int j=0; j<v[0].size(); j++){
    //        cout << v[i][j] << " ";
    //    }
    //    cout << '\n';
    //}

    int answer=0;
    for(int i =0; i<v.size()-1; i++){
        int curr_num =v[i][0], next_num =v[i+1][0];
        int curr_pos =v[i][1], next_pos =v[i+1][1];
        // 같은 비둘기인데 위치가 달라짐
        if(curr_num==next_num && curr_pos !=next_pos) answer++;
    }
    cout << answer;
    return 0;
}