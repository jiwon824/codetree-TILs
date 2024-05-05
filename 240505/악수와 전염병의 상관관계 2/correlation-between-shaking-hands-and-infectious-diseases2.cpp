#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n: N명의 개발자
// k: 이 병에 감염된 후에는 정확히 K번의 악수 동안만 전염병을 옮기게 되고, 그 이후부터는 전염병에 걸려있지만 새로 옮기지는 않게 됩니다.
// p: 처음 전염병에 걸려 있는 개발자의 번호 P
// t: T번에 걸쳐 (t초에 x개발자가 y개발자와 악수를 나눈) 정황
int n, k, p, t;
bool infection_status[101]= {false, }; // 감염 여부
int num_of_infections[101]; // 감염된 후에 i번째 인덱스가 k로 갱신됨
vector<vector<int>> record_handshakes; // {sec, x, y}

bool cmp_time(vector<int> &v1, vector<int> &v2){
    return v1[0]<v2[0];
}

void Infect(){
    for(int i=0; i<record_handshakes.size(); i++){
        int x = record_handshakes[i][1], y = record_handshakes[i][2];
        // 둘 다 감염횟수가 남은 경우 감염회수 초기화
        if((infection_status[x] && num_of_infections[x]>0)&&(infection_status[y] && num_of_infections[y]>0)){
            num_of_infections[x]=k;
            num_of_infections[y]=k;
        }
        // x가 감염상태이면서, 감염시킬 수 있는 횟수가 남은 경우
        else if(infection_status[x] && num_of_infections[x]>0){
            infection_status[y]=true; // y감염됨
            num_of_infections[y]=k; // y는 k번 감염시킬 수 있음
            num_of_infections[x]--; // x는 1번 감염시켰으므로 감염가능횟수--
        }
        // y가 감염상태이면서, 감염시킬 수 있는 횟수가 남은 경우
        else if(infection_status[y] && num_of_infections[y]>0){
            infection_status[x]=true; // x감염됨
            num_of_infections[x]=k; // x는 k번 감염시킬 수 있음
            num_of_infections[y]--; // x는 1번 감염시켰으므로 감염가능횟수--
        }
    }
}
int main() {
    cin >> n >> k >> p >> t;
    for(int i=0; i<t; i++){
        int sec, x, y;
        cin >> sec >> x >> y;
        record_handshakes.push_back({sec, x, y});
    }
    
    // 시간순으로 정렬
    sort(record_handshakes.begin(), record_handshakes.end(), cmp_time);

    // 첫 감염자 p 체크
    infection_status[p]=true;
    num_of_infections[p]=k; //p는 k번 감염시킬 수 있음
    Infect();
    
    for (int i=1; i<=n; i++){
        cout << infection_status[i];
    }

    return 0;
}