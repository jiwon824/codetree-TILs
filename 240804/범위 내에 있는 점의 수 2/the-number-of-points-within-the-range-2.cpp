#include <iostream>
using namespace std;

int arr[1000001];
int prefix_sum[1000001];

int main() {
    // input
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        arr[num]=1;
    }

    // solution
    // 누적합 구하기
    prefix_sum[0]=arr[0];
    for(int i=1; i<=1000001; ++i){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }
    
    // 범위에 있는 점 개수 출력
    while(q--){
        int start, end;
        cin >> start >> end;
        cout << prefix_sum[end]-prefix_sum[start-1] << '\n';
    }
    return 0;
}