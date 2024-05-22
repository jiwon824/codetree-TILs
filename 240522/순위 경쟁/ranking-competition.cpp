#include <iostream>

using namespace std;

int score[3];

string Winner_list(){
    int max_score = max(score[0], max(score[1], score[2]));
    string winner="000";
    for(int i=0; i<3; i++){
        if(score[i]==max_score) winner[i]=1;
    }
    return winner;
}

int main() {
    int n;
    cin >> n;

    int cnt =0;
    for(int i=0; i<n; i++){
        char person;
        int input_score;
        cin >> person >>input_score;
        // 이전의 승자 목록
        string recent_winner_list = Winner_list();
        score[person-'A']+=input_score; // input_score 더하기
        // input_score를 더한 후 승자 목록
        string curr_winner_list = Winner_list();

        if(recent_winner_list!=curr_winner_list) cnt++;
    }

    cout << cnt<< '\n';
    return 0;
}