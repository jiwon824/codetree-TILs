#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int max_len=1, length=1;
    for(int i=1; i<n; i++){
        if(arr[i-1]==arr[i]) length++;
        else{
            max_len = max(length, max_len);
            length=1;
        }
    }
    cout << max_len;
    return 0;
}