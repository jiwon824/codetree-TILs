#include <iostream>

using namespace std;

int main() {
    string brackets;
    cin >> brackets;

    int answer=0;
    for(int i=1; i<brackets.length(); i++){
        if (brackets[i-1]=='(' && brackets[i]=='('){
            for(int j=i+1;j<brackets.length()-1;j++){
                if(brackets[j]==')' && brackets[j+1]==')') answer++;
            }
        }
    }
    cout << answer;
    return 0;
}