#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<string, int> um;

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        string str;
        cin >> str; 
        um[str]=i+1;
    }

    // m개의 숫자(value) 혹은 문자열(key)에 대응되는 짝 출력
    for(int i=0; i<m; ++i){
        string inspect;
        cin >> inspect;
        if('a'<=inspect[0] && inspect[0]<='z')
            cout << um.find(inspect)->second << '\n';
        else{
            for(auto it=um.begin(); it!=um.end(); it++){
                if(to_string(it->second)==inspect){
                    cout << it->first << '\n';
                }
            }
        }
    }
    
    return 0;
}