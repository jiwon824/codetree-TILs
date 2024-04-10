#include <iostream>

using namespace std;
int main() {
    string a;
    cin >> a;
    int answer =0;
    for (int i=0; i<a.length();i++){
        if (a[i]=='('){
            for (int j=i+1;j<a.length();j++){
                if(a[j]==')'){
                    answer++;
                    continue;
                }
            }
        }
    }
    cout << answer;
    return 0;
}