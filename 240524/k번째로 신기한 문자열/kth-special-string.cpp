#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> str;
int main() {
    int n, k;
    string t;
    cin >> n >> k >> t;
    for(int i=0; i<n; i++){
        string input_str;
        cin >>input_str;
        if(input_str.length()<t.length()) continue;
        bool start_to_t=true;
        for(int j=0; j<t.length(); j++){
            if(input_str[j]!=t[j]){
                start_to_t=false;
                break;
            }
        }
        if(start_to_t) str.push_back(input_str);
    }
    sort(str.begin(), str.end());
    cout << str[k-1];
    return 0;
}