#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int *arr= new int[n];
    for (int i=0; i<k;i++){
        int a, b;
        cin >> a >> b;
        for (int j=a ; j<=b;j++){
            arr[j]++;
        }
    }

    sort(arr, arr+n, greater<int>());
    cout << arr[0];

    return 0;
}