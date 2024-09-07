#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int n;
vector<string> num;

bool cmp(string a, string b){
    string ab = a+b, ba=b+a;
    return stoll(ab)>stoll(ba);
}

int main() {
    cin >> n;
    num.resize(n);
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    sort(num.begin(), num.end(), cmp);

    for(int i=0; i<n; ++i){
        cout << num[i];
    }
    return 0;
}