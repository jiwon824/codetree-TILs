#include <iostream>
#define MAX_N 100000
using namespace std;

int opening[MAX_N];// 연속((

int main() {
    string a;
    cin >> a;
    
    long long answer=0;
    for(int i=1; i<a.length(); ++i){
        if(a[i-1]=='(' && a[i]=='(') opening[i]=opening[i-1]+1;
        else opening[i]=opening[i-1];
        if (a[i-1]==')' && a[i]==')') answer += opening[i];
    }
    cout << answer << '\n';
    return 0;
}