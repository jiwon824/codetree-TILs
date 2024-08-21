#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int main() {
    cin >> n >> k;
    vector<pair<int,int> > bomb(n);
    for(int i=0; i<n; ++i){
        int bombNum;
        cin >> bombNum;
        bomb[i].first = bombNum;
        bomb[i].second = i;
    }

    int answer=-1;
    sort(bomb.begin(), bomb.end(), greater<>());
    for(int i=1; i<(int)bomb.size(); ++i){
        int bombNum = bomb[i].first;
        if(bomb[i-1].first==bombNum){
            int dist = bomb[i-1].second-bomb[i].second;
            if(dist<=k){
                answer=bombNum;
                break;
            }
        }
    }
    cout << answer << '\n';

    return 0;
}