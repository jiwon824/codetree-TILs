#include <iostream>

using namespace std;

// 가장 가까운 두 사람의 거리를 구하는 함수
int Solution(string s, int idx){
    string str = s;
    str[idx]='1';
    int min_dist = str.length();
    for(int i=0; i<str.length(); i++){
        if(str[i]=='1'){

            for(int j=i+1; j<str.length(); j++){
                if(str[j]=='1'){
                    if(j-i<min_dist) min_dist = j-i;
                }
            }
            
        }
    }
    return min_dist;
}
int main() {
    int n;
    string chair;
    cin >> n >> chair;
    
    int answer =0; // 
    for (int i=0; i<n; i++){
        if(chair[i]=='1') continue;
        // i번째 자리에 앉혔을 때 가장 가까운 두 사람의 거리
        int near_dist=Solution(chair, i);
        if(answer < near_dist) answer = near_dist;
    }
    cout << answer;
    return 0;
}