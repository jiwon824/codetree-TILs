#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> words;
    for(int i=0; i<n; ++i){
        string str;
        cin >> str;
        words[str]++;
    }

    for(auto it=words.begin(); it!=words.end(); ++it){
        string word = it->first;
        int appear = it->second;
        cout << word << " " << appear << '\n';
    }
    return 0;
}