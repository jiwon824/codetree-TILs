#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    int *arr = new int[n];
    bool exist = false;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]>t) exist =true;
    }

    int max_len =1, len=1;
    if(exist){
        for(int i=1; i<n; i++){
            if(arr[i-1]>t && arr[i]>t){
                len++;
                exist = true;
            }
            else{
                max_len = max(max_len, len);
                len=1;
            }
        }
        max_len = max(max_len, len);
    }
    else max_len = 0;
    
    cout << max_len;
    return 0;
}