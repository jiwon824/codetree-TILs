#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX_N = 100001;

int n, k;
int num[MAX_N];
unordered_map<int,int> um;

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    int r=0, answer=1;
    for(int l=0; l<n; ++l){
        // um에 num[r]이 없거나 k개보다 적을 경우
        while(r<n && (um.find(num[r])==um.end()|| um[num[r]]<k)){
            um[num[r]]++;
            r++;
        }
        answer=max(answer, r-l);
        um[num[l]]--;
    }
    cout << answer << '\n';
    return 0;
}