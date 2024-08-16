#include <iostream>
#define MAXLEN 100000
using namespace std;

char str[MAXLEN];
long long lC[MAXLEN];// 왼쪽에서 부터 C의 개수
long long rW[MAXLEN];// 오른쪽에서부터 W의 개수

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> str[i];
    }

    // left C
    lC[0]=(str[0]=='C')? 1:0;
    for(int i=1; i<n; ++i){
        lC[i]=(str[i]=='C')? lC[i-1]+1:lC[i-1];
    }
    // right W
    rW[n-1]=(str[n-1]=='W')? 1:0;
    for(int i=n-2; i>=0; --i){
        rW[i]=(str[i]=='W')? rW[i+1]+1:rW[i+1];
    }

    // answer
    long long answer=0;
    for(int i=1; i<n-1; ++i){
        if(str[i]=='O'){
            answer+=lC[i-1]*rW[i+1];
        }
    }
    cout << answer <<'\n';
    return 0;
}