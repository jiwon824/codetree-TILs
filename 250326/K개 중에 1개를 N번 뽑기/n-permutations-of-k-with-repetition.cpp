#include <iostream>
#include <vector>

using namespace std;

int K, N;

vector<int> picked;

void backtracking(int cnt){
    if(cnt>=N){
        for(auto num : picked){
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=K; i++){
        picked.push_back(i);
        backtracking(cnt+1);
        picked.pop_back();
    }
}

int main() {
    cin >> K >> N;
    backtracking(0);
    return 0;
}
