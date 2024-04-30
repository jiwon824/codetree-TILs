#include <iostream>
#include <climits>

using namespace std;
int num[101];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n ;i++){
        cin >>num[i];
    }

    int min_diff = INT_MAX;
    for(int i=0; i<n; i++){
        // i번째 수를 2배한다 
        num[i] *=2;
        for(int j=0; j<n; j++){
            int remain_num[101]={0, };
            int idx =0;
            // j번째 수를 제외하고 remain_num 배열에 넣는다
            for(int k=0; k<n; k++){
                if(k!=j) remain_num[idx++]=num[k];
            }
            
            int diff_sum =0;
            for(int k=1; k<n-1; k++){
                diff_sum += abs(remain_num[k-1]-remain_num[k]);
            }
            if(diff_sum<min_diff) min_diff=diff_sum;
        }

        num[i]/=2;
    }
    cout << min_diff;
    return 0;
}