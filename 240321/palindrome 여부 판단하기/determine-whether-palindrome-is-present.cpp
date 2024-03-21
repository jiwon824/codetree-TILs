#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool IsPalindrome(string &s){
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(s==tmp) return true;
    else return false;
}
int main() {
    string a;
    cin >> a;
    if(IsPalindrome(a)) cout << "Yes";
    else cout << "No";
    return 0;
}