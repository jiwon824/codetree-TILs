#include <iostream>
#define MAX_N 100000
using namespace std;

int opening[MAX_N];// 연속((
int closing[MAX_N]; // 연속))

int main() {
    string a;
    cin >> a;
    // 연속 여는 괄호 체크
    for(int i=1; i<a.length(); ++i){
        if(a[i-1]=='(' && a[i]=='(') opening[i]=opening[i-1]+1;
        else opening[i]=opening[i-1];
    }
    // 연속 닫는 괄호 체크
    for(int i=a.length()-2; i>=0; --i){
        if(a[i+1]==')' && a[i]==')') closing[i]=closing[i+1]+1;
        else closing[i]=closing[i+1];
    }

    int answer=0;
    for(int i=1; i<a.length(); ++i){
        answer = max(answer, opening[i]*closing[i+1]);
    }
    cout << answer <<'\n';
    return 0;
}