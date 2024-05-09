#include <iostream>

using namespace std;

int n, k;
int bomb[101];
int num_of_explosion[1000001]; //idx번 폭탄이 몇 번 터졌는지 기록

bool IsExplosion(int bomb_idx){
    // 거리 k 안에 같은 번호가 있는지 검사
    int bomb_num = bomb[bomb_idx];
    // 배열 범위를 벗어나지 않도록 i값 설정
    for(int i=max(0, bomb_idx-k); i<=min(bomb_idx+k, n); i++){
        if(i==bomb_idx) continue; // 자기자신
        if(bomb[i]==bomb_num) {
            //cout << "일치하는 idx: " << i <<'\n';
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> bomb[i];
    }

    for(int i=0; i<n; i++){
        if(IsExplosion(i)) num_of_explosion[bomb[i]]++;
        //cout << num_of_explosion[bomb[i]]<<'\n';
    }

    int max_explosion =0, answer=0;
    for(int i=0; i<n; i++){
        int bomb_num = bomb[i];
        if(max_explosion<=num_of_explosion[bomb_num]) {
            //cout << num_of_explosion[bomb_num] <<'\n';
            max_explosion=num_of_explosion[bomb_num];
            if(num_of_explosion[bomb_num]!=0) answer=i;
        }
    }
    cout << answer;
    return 0;
}