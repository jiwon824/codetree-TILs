#include <iostream>
#include <algorithm>
using namespace std;

void Input(int *arr, int n){
    for (int i=0;i<n;i++){
        cin>> arr[i];
    }
}
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    Input(a, n);
    Input(b, n);
    
    sort(a, a+n);
    sort(b, b+n);
    
    bool isSame = true;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            isSame = false;
            break;
        }
    }

    if (isSame) cout << "Yes";
    else cout << "No";
    return 0;
}