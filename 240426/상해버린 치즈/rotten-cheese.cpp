#include <iostream>
#include <algorithm>

#define MAX_CHEESE 51

using namespace std;

int n, m, d, s;
bool spoiled_cheese[MAX_CHEESE] = {false, };
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
    cin >> n >> m >> d >> s;

    // p번째 사람(infos.person)이 m번째 치즈(infos.cheese)를 언제(t초, infos.time) 먹었는지 정보(d개)
    Info infos[d];
    for(int i=0; i<d; i++){
        int p, m, t;
        cin >> p >> m >> t;
        infos[i] = Info(p, m, t);
    }

    sort(infos, infos+d, cmp);

    // p번째 사람이 언제(t초) 아팠는지 기록 -> 상한 치즈 체크
    for(int i=0; i<s; i++){
        int p, t;
        cin >> p >> t;
        // p번째 사람이 t초 전에 먹은 치즈 전부 수상해
        for(int j=0; j<d; j++){
            if(infos[j].person != p) continue;
            if(infos[j].time<t) spoiled_cheese[infos[j].cheese] =true;
            //cout << spoiled_cheese[infos[j].cheese] <<'\n';
        }
    }

    // 상한 치즈를 먹은 사람 체크
    bool patient[50];
    for(int i=0; i<d; i++){
        // i에 있는 치즈가 상한 치즈라면
        if(spoiled_cheese[infos[i].cheese]){
            patient[infos[i].person] =true;
            //cout << infos[i].person << '\n';
        }
    }
    
    // n명을 돌면서 환자라면 필요한 약의 갯수 +=1
    int num_of_medications=0;
    for(int i=1; i<=n; i++){
        if(patient[i]) num_of_medications++;
    }
    cout << num_of_medications;
    return 0;
}