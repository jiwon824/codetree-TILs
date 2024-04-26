#include <iostream>
#include <algorithm>

#define MAX_EAT 1000
#define MAX_CHEESE 50

using namespace std;

int n, m, d, s;
int suspicious_cheese[MAX_CHEESE];
class Info{
    public:
        int person, cheese, time;

    Info(){};
    Info(int person, int cheese, int time){
        this->person = person;
        this->cheese = cheese;
        this->time = time;
    };
};

// n번째 사람이 시간순으로 먹은 치즈를 알 수 있도록 정렬
bool cmp(Info a, Info b){
    if(a.person==b.person){
        return a.time<b.time;
    }
    return a.person<b.person;
}

// 상한 치즈를 먹은 사람에게 약을 복용시켜야 할 때
// 약이 최대 몇 개나 필요할지를 구하는 프로그램을 작성
int main() {
    // ==============[input]==============
    cin >> n >> m >> d >> s;

    // p번째 사람(infos.person)이 m번째 치즈(infos.cheese)를 언제(t초, infos.time) 먹었는지 정보(d개)
    Info infos[d];
    for(int i=0; i<d; i++){
        int p, m, t;
        cin >> p >> m >> t;
        infos[i] = Info(p, m, t);
    }

    //sort(infos, infos+d, cmp);

    // p번째 사람이 언제(t초) 아팠는지 기록
    for(int i=0; i<s; i++){
        int p, t;
        cin >> p >> t;
        for(int j=0; j<d; j++){
            if(infos[j].person!=p) continue;
            if(infos[j].time<t) suspicious_cheese[infos[j].cheese]++;
        }
    }

    // ==============[Solution]==============
    // 아픈 사람들이 공통으로 먹은 치즈(suspicious_cheese[i]==s)가 수상한 치즈(i).
    // m은 치즈 갯수
    
    int answer =0;
    for(int i=0; i<=m; i++){
        //cout << suspicious_cheese[infos[i].cheese] << "가 수상할까?\n";
        if(suspicious_cheese[i]>=s){
            //cout<< i <<"번 치즈가 수상하다\n";
            bool patients[50] = {false, }; 
            for(int j=0; j<d; j++){
                if(infos[j].cheese==i) {
                    patients[infos[j].person] = true;
                    //cout << infos[j].person <<"은 i번 치즈를 먹었다\n";
                }
            }

            int num_of_patients=0;
            for(int j =0; j<=n;j++){
                if(patients[j]) num_of_patients++;
            }
            //cout << i << "번 치즈는 "<< num_of_patients << "명을 아프게 했다\n";
            if(answer<num_of_patients) answer= num_of_patients;
        }
    }

    cout << answer;
    return 0;
}