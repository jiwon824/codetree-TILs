#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 50001;

int n, k;
int arr[MAX_N];

int Solution() {
    int l[MAX_N], r[MAX_N];

    // l 배열
    int max_num = 0;
    int i = 0;
    for (int j=0; j<n; j++) {
        // 구간 내 차이가 K를 넘는다면 i를 오른쪽으로 이동
        while (i<n && arr[j]-arr[i] > k) {
            i++;
        }

        // 현재 구간 [i, j]의 최대 크기 갱신
        max_num = max(max_num, j-i+1);
        l[j] = max_num;
    }

    // R 배열
    max_num=0;
    int j=n-1;
    for (int i=n-1; i>=0; i--) {
        // 구간 내 차이가 K를 넘는다면 j를 왼쪽으로 이동
        while (j>0 && arr[j]-arr[i] > k) {
            j--;
        }

        // 현재 구간 [i, j]의 최대 크기 갱신
        max_num = max(max_num, j-i+1);
        r[i] = max_num;
    }

    int max_cnt = l[n-1];
    for (int i=0; i<n-1; ++i) {
        max_cnt = max(max_cnt, l[i] + r[i+1]);
    }

    return max_cnt;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << Solution() << '\n';
    return 0;
}