#include <iostream>

using namespace std;

// 가장 가까운 두 사람의 거리를 반환하는 함수
int Solution(string str, int i, int j){
    string tmp = str;
    tmp[i]='1';
    tmp[j]='1';
    
    int dist_of_close_people = 100;
    for(int i=0; i<tmp.length(); i++){
        if(tmp[i]=='0') continue;
        for(int j=i+1; j<tmp.length(); j++){
            if(tmp[j]=='0') continue;
            int dist = j-i;
            if(dist<dist_of_close_people) dist_of_close_people = dist;
            break;
        }
    }
    return dist_of_close_people;
}

int main() {
    int n;
    string chair;
    cin >> n >> chair;
    
    //i번째 자리와 j번째 자리에 두 사람을 배치할 경우
    // 가장 가까운 두 사람의 거리의 최대값
    int answer = 0;
    for(int i=0; i<n; i++){
        if(chair[i]=='1')continue;
        for(int j=i+1; j<n; j++){
            if(chair[i]=='1')continue;
            int dist = Solution(chair, i, j);
            if(answer<dist)answer = dist;
        }
    }
    cout << answer;
    return 0;
}