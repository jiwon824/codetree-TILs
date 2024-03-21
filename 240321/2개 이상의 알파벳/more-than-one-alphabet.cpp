#include <iostream>

using namespace std;
bool Solution(string &s){
    for (int i=0;i<(int)s.size();i++){
        if(i>=1 && s[i-1]!=s[i]) return true;
    }
    return false;
}
int main() {
    string a;
    cin >> a;
    if(Solution(a)) cout <<"Yes";
    else cout << "No";
    return 0;
}