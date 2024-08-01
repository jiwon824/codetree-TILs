#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n, k;
int currState[100001];
vector<pair<int,int>> changeList;

void Swap(int& a, int& b){
    int tmp = a;
    a= b;
    b= tmp;
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<k; ++i){
        int a, b;
        cin >> a >> b;
        changeList.push_back({a, b});
    }

    // solution
    // seats[i] i번째 사람이 앉았던 자리
    // 맨 처음에 i번째 사람은 i번째 자리에 앉기 때문에 i를 넣어준다
    vector<unordered_set<int>> seats(n+1);
    for(int i=1; i<=n; ++i){
        currState[i]=i;
        seats[i].insert(i);
    }

    // 자리 바꿈이 이뤄지는 동안 앉게 되는 자리
    // 3k번에 걸쳐 자리 바꿈 진행
    for(int i=0; i<3; ++i){
        for(int j=0; j<k; ++j){
            int a=changeList[j].first, b=changeList[j].second;
            // 현재 a자리에 앉은 사람은 b에 앉고, 현재 b자리에 앉은 사람음 a에 앉음
            seats[currState[a]].insert(b);
            seats[currState[b]].insert(a);

            // 자리 바꾸기
            Swap(currState[a], currState[b]);
        }
    }

    // output
    for(int i=1; i<=n; ++i){
        cout << (int)seats[i].size() << '\n';
    }
    return 0;
}