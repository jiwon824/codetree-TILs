#include <iostream>
using namespace std;

const int MAX_N=50001;

int n;
int num[MAX_N];
long long prefixSum[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> num[i];
    }

    prefixSum[0]=num[0];
    for(int i=1; i<n; ++i){
        prefixSum[i]=prefixSum[i-1]+num[i];
    }
    
    int answer =0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            long long tmp = prefixSum[i]-prefixSum[j];
            if(tmp%7==0){
                answer = max(answer, i-j);
                break; // 이것보다 짧은 구간은 볼 필요 없어짐
            }
        }
    }
    cout << answer << '\n';
    return 0;
}