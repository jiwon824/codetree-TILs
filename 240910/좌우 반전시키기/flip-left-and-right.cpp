#include <iostream>
using namespace std;

const int MAX_N = 101;
int n;
char num[MAX_N];

void Change(int idx){
    if(num[idx]=='0') num[idx]='1';
    else num[idx]='0';
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }
    
    int checkIdx=1, answer=0;
    while(checkIdx<n){
        if(num[checkIdx-1]=='0'){
            for(int i=-1; i<=1; ++i){
                Change(checkIdx+i);
            }
            answer++;
        }
        checkIdx++;
    }

    if(num[n-1]=='0') answer=-1;
    cout << answer << '\n';
    return 0;
}