#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, int> m;

void Add(int k, int v){
    // 키 값이 해시 맵에 이미 있다면 아무런 행동을 취하지 않음
    //m.insert({k, v}); 

    // 키 값이 해시 맵에 이미 있으면 기존의 값을 value로 바꾸고, 없으면 해당 키 값에 value를 추가
    m[k]=v;
}

void Remove(int k){
    m.erase(k);
}

int FindKey(int k){
    if(m.find(k)==m.end()) return -1;
    return m.find(k)->second;
}

int main() {
    // input
    cin >> n;
    
    // solution
    while(n--){
        string command;
        cin >> command;

        if(command=="add") {
            int key, value;
            cin>> key >> value;
            Add(key, value);
        }
        if(command=="remove") {
            int key;
            cin >> key;
            Remove(key);
        }
        if (command=="find") {
            int key;
            cin >> key;
            int result = FindKey(key);
            if(result == -1) cout << "None\n";
            else cout << result << '\n';
        }
    }

    return 0;
}