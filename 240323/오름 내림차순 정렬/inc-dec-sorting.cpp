#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr= new int[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    // 일반적으로는 평균 시간복잡도가 O(NlgN)인 퀵 정렬이 많이 이용된다.
    // 다만 최근 Python, Java 등의 언어에서의 sort 함수는 Tim Sort로 이루어져 있다고 한다
    sort(arr, arr+n);
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout <<'\n';
    
    sort(arr, arr+n, greater<int>());
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}