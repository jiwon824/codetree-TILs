#include <iostream>
using namespace std;

string str;
int str_cnt[26];

int main() {
    cin >> str;
    int size = str.length();

    int r=0, answer=0;
    for(int l=0; l<size; ++l){
        while(r<size && str_cnt[str[r]]==0){
            str_cnt[str[r]]=1;
            r++;
        }
        answer= max(answer, r-l);
        str_cnt[str[l]]=0;
    }
    cout << answer <<'\n';
    return 0;
}