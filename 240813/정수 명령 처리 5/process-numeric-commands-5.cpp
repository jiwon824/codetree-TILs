#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n--){
        string command;
        cin >> command;
        if(command=="push_back"){
            int num;
            cin >> num;
            v.push_back(num);
        }
        if(command=="pop_back"){
            v.pop_back();
        }
        if(command=="size"){
            cout << (int)v.size() << '\n';
        }
        if(command=="get"){
            int idx;
            cin >> idx;
            cout << v[idx-1] << '\n';
        }
    }
    return 0;
}