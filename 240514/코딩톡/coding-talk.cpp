#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> msg;
bool isRead[27];

/*
6 6 5
D 0 // ABCDEF
C 1 // ABCF
B 2 // ABF
B 2 // ABF
A 2 // ABF
F 4 // F

*/
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i=0; i<m; i++){
        char c;
        int u;
        cin >> c >> u;
        msg.push_back({c, u});
    }

    // 0부터 시작하기 때문에 확인할 메세지 = msg[p-1]
    // 모든 사람이 다 읽었으면 출력x
    if(msg[p-1].second == 0) return 0;

    // 확인할 메세지 이후에 메세지를 보낸 사람 전부 체크
    for(int i=p-1; i<m; i++){
        int sender = msg[i].first -'A';
        isRead[sender] = true;
    }

    // 확인해야 할 메세지랑 읽은 사람이 같은 이전 메세지
    for(int i=p-1; i>=0; i--){
        if(msg[p-1].second != msg[i].second) break;// 읽은 사람의 수가 달라지면 break
        int sender = msg[i].first -'A';
        isRead[sender] = true;
    }

    
    for(int i=0; i<n; i++){
        char reader = (char)i+'A';
        if(isRead[i]==false) cout << reader << " ";
    }

    return 0;
}