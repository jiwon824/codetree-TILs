#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 50001;

int n, k;
int arr[MAX_N];
int l[MAX_N];
int r[MAX_N];

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }   

    sort(arr, arr+n);

    // l배열 prefix_sum
    // 왼쪽부터 k 차이가 k를 넘지 않으면 더하기
    int min_val =arr[0];
    l[0]=1;
    for(int i=1; i<n; ++i){
        // arr[i]가 항상 최대값이므로 min_val과 차이가 k를 넘는지 보면 됨
        if(arr[i]-min_val<=k){
            l[i]=l[i-1]+1;
        }
        else{
            l[i]=1;
            min_val=arr[i];
        }
    }

    // r배열 prefix_sum
    int max_val =arr[n-1];
    r[n-1]=1;
    for(int i=n-2; i>=0; --i){
        // arr[i]가 항상 최대값이므로 min_val과 차이가 k를 넘는지 보면 됨
        if(max_val-arr[i]<=k){
            r[i]=r[i+1]+1;
        }
        else{
            r[i]=1;
            max_val=arr[i];
        }
    }
    
    int answer=0;
    for(int i=0; i<n; i++){
        answer = max(answer, l[i]+r[i]);
    }
    if(n==1) cout << 1 << '\n';
    else cout << answer << '\n';
    return 0;
}