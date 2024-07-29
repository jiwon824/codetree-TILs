#include <iostream>
#include <unordered_map>

using namespace std;


int n;
unordered_map<string, int> um;

int main() {
    cin >> n;

    int answer=0;
    for(int i=0; i<n; ++i){
        string str;
        cin >> str;
        um[str]++;
        answer=max(answer, um[str]);
    }

    cout << answer << '\n';
    return 0;
}