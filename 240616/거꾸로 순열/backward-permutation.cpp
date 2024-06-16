#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num;
bool visited[9]={false, };

void Solution(int currLen){
    if(currLen==n){
        for(auto e : num){
            cout << e << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=n; i>=1; --i){
        if(visited[i]) continue;
        num.push_back(i);
        visited[i]=true;

        Solution(currLen+1);

        num.pop_back();
        visited[i]=false;
    }
}
int main() {
    cin >> n;
    Solution(0);
    return 0;
}