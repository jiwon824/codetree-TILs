#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > meeting_time;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main() {
    cin >> n;
    meeting_time.resize(n);
    for(int i=0; i<n; ++i){
        cin >>meeting_time[i].first >> meeting_time[i].second;
    }

    sort(meeting_time.begin(), meeting_time.end(), cmp);
    
    int answer=1, lastEndTime=meeting_time[0].second;
    for(int i=1; i<n; ++i){
        if(meeting_time[i].first<lastEndTime)continue;
        answer++;
        lastEndTime=meeting_time[i].second;
    }
    cout << answer << '\n';
    return 0;
}