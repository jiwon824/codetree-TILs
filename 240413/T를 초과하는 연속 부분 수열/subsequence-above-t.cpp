#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int max_len =1, len=1;
    bool exist =false;
    for(int i=1; i<n; i++){
        if(arr[i]>t && arr[i-1]<arr[i]){
            len++;
            exist = true;
        }
        else{
            max_len = max(max_len, len);
            len =1;
        }
    }
    max_len = max(max_len, len);
    if(exist) cout << max_len;
    else cout << '0';
    return 0;
}