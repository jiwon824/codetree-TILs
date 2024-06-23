#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> num;
bool visited[11]={false, };

void Choose(int chosen, int cnt){
    // 종료조건
    if(cnt==m){
        for(size_t i=0; i<num.size(); ++i){
            cout << num[i] << " ";
        }
        cout << '\n';
        return;
    }

    // 재귀호출
    for(int i=chosen; i<=n; ++i){
        if(visited[i]) continue;

        num.push_back(i);
        visited[i]= true;
        Choose(i, cnt+1);

        num.pop_back();
        visited[i]=false;
    }
}

int main() {
    cin >> n >> m;

    Choose(1, 0);

    return 0;
}