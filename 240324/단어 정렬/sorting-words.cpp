#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >>n;
    string* s = new string[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    sort(s, s+n);
    for(int i=0;i<n;i++){
        cout << s[i] << '\n';
    }
    return 0;
}