#include <iostream>
#include <unordered_map>

using namespace std;


int n;
unordered_map<string, int> um;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        string str;
        cin >> str;
        um[str]++;
    }

    int answer=0;
    for(auto it=um.begin(); it!=um.end(); ++it){
        answer=max(answer, it->second);
    }
    cout << answer << '\n';
    return 0;
}