#include <iostream>
using namespace std;

const int MAX_N = 100001;
const int MAX_B = 1000001;

int n, k;
int basket[MAX_B];
int prefix_sum[MAX_B]; // 100,000 * 10,000=1e9

int main() {
    cin >> n >> k;
    int max_coord=0;
    for(int i=0; i<n; ++i){
        // 사탕개수 >> 바구니 좌표
        int candy, coord;
        cin >> candy >> coord;
        basket[coord]+=candy;
        max_coord=max(max_coord, coord);
    }

    // prefix 계산
    prefix_sum[0]=basket[0];
    for(int i=1; i<=max_coord; ++i){
        prefix_sum[i]=prefix_sum[i-1]+basket[i];
    }

    int max_candy=0;
    for(int l=0; l<=max_coord; ++l){
        int r = 2*k+l;
    // r이 범위를 초과하면 max_coord로 조정
        if (r>max_coord) r=max_coord;

        if(l==0)max_candy = max(max_candy, prefix_sum[r]);
        else max_candy = max(max_candy, prefix_sum[r]-prefix_sum[l-1]);
        r++;
    }

    cout << max_candy << '\n';
    return 0;
}