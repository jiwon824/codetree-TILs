#include <iostream>

using namespace std;

int main() {
    int n;
    string seats;
    cin >> n >> seats;
    
    // step1. 가장 거리가 먼 1 쌍 찾기
    int left_idx=0, right_idx=0, max_dist =0;
    for(int i=0; i<n-1; i++){
        if(seats[i]=='0') continue;
        int dist=0;
        for(int j=i+1; j<n; j++){
            if(seats[j]=='0') dist++;
            else break;
        }
        if(max_dist<dist) {
            max_dist=dist;
            left_idx = i;
            right_idx = i+dist+1;
        }
    }

    // step2. 가장 거리가 먼 두 사람의 가운데에 1 넣기
    int mid_idx = (left_idx+right_idx)/2;
    seats[mid_idx]='1';

    //cout << left_idx << " " << right_idx << " " << mid_idx <<'\n';
    //cout << seats<<'\n';

    // step3. 두 사람이 떨어진 거리가 가장 가까운 경우
    left_idx=n, right_idx=0;
    int min_dist=n;
    for(int i=0; i<n-1; i++){
        if(seats[i]=='0') continue;
        int dist=0;
        for(int j=i+1; j<n; j++){
            if(seats[j]=='0') dist++;
            else break;
        }
        if(dist<min_dist) {
            min_dist= dist;
            left_idx =i;
            right_idx=i+dist+1;
            //cout << left_idx << " " << right_idx <<'\n';
        }
    }

    cout << right_idx-left_idx <<'\n';
    return 0;
}