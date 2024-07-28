#include <iostream>
#include <vector>

using namespace std;

int n, m, player, answer;
int dist[13]; // 각 턴에 나아갈 수 있는 거리
vector<int> selectedPlayer;

int Scoring(){
    // 모든 플레이어는 1에서 시작함
    int result[5]={1, 1, 1, 1, 1};
    for(size_t i=0; i<selectedPlayer.size(); ++i){
        result[selectedPlayer[i]] += dist[i];    
    }

    int score=0;
    for(int i=1; i<=player; ++i){
        if(result[i]>=m) score++;
    }
    return score;
}

void Select(int currSelect){
    // 종료 조건
    if(currSelect==n) {
        answer = max(answer, Scoring());
        return;
    }

    // 재귀호출
    for(int i=1; i<=player; ++i){
        selectedPlayer.push_back(i);
        Select(currSelect+1);
        selectedPlayer.pop_back();
    }
}

int main() {
    // intput
    cin >> n >> m >> player;
    for(int i=0; i<n; ++i){
        cin >> dist[i];
    }

    // solution
    Select(0);

    // output
    // n번의 턴을 거친 이후에 최대로 얻을 수 있는 점수
    cout << answer << '\n';
    return 0;
}