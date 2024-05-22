#include <iostream>

using namespace std;

int score[3];

bool Is_Change_Hall_of_Fame(string past, string curr){

    int past_max_score = max(past[0], max(past[1], past[2]));
    int past_hall_of_fame[3]={0, };
    for(int i=0; i<3; i++){
        if(past[i]==past_max_score) past_hall_of_fame[i]=1;
    }

    int curr_max_score = max(curr[0], max(curr[1], curr[2]));
    int curr_hall_of_fame[3]={0, };
    for(int i=0; i<3; i++){
        if(curr[i]==curr_max_score) curr_hall_of_fame[i]=1;
    }

    for(int i=0; i<3; i++){
        // 바뀌었으면 Change= true;
        if(past_hall_of_fame[i]!=curr_hall_of_fame[i]) return true;
    }
    // return된 적 없으면 안 바뀜 false;
    return false;
}

int main() {
    int n;
    cin >> n;

    string recent_scores="000";
    int cnt =0;
    for(int i=0; i<n; i++){
        char person;
        int input_score;
        cin >> person >>input_score;

        score[person-'A']+=input_score;
        string curr_score ="";
        for(int j=0; j<3; j++){
            char ch_j = score[j]+'0'; // -1이 '/'로 표현되는 문제가 있으나 문제 풀이에는 지장이 없다
            curr_score= curr_score+ch_j;
        }
        if(Is_Change_Hall_of_Fame(recent_scores, curr_score)) cnt++;
        recent_scores = curr_score;
    }

    cout << cnt<< '\n';
    return 0;
}