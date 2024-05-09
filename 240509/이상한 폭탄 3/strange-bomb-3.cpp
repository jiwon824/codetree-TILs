#include <iostream>

using namespace std;

int n, k;
int bomb[101];
int num_of_explosion[101];

bool IsExplosion(int bomb_idx){
    // 거리 k 안에 같은 번호가 있는지 검사
    int bomb_num = bomb[bomb_idx];
    for(int i=bomb_idx-k; i<=bomb_idx+k; i++){
        if(i<0 || i>n || i==bomb_idx) continue; // 배열 범위를 벗어남 || 자기자신
        if(bomb[i]==bomb_num) return true;
    }
    return false;
}
int main() {
    cin >> n >> k;
    int min_bomb_num=1000000, max_bomb_num=0;
    for(int i=0; i<n; i++){
        cin >> bomb[i];
        if(bomb[i]<min_bomb_num) min_bomb_num=bomb[i];
        if(max_bomb_num<bomb[i]) max_bomb_num = bomb[i];
    }

    for(int i=0; i<n; i++){
        if(IsExplosion(i)) num_of_explosion[bomb[i]]++;
    }

    int max_explosion =0, answer=0;
    for(int i=min_bomb_num; i<=max_bomb_num; i++){
        if(max_explosion<num_of_explosion[i]) {
            max_explosion= num_of_explosion[i];
            answer=i;
        }
    }
    cout << answer;
    return 0;
}