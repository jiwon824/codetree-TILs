#include <iostream>

using namespace std;

int arr[101];
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    bool exist = false;
    for(int i=0; i<m;i++){
        int num;
        cin >> num;
        arr[num-1]++;
        if(arr[num-1]>=k) {
            exist = true;
            cout << num;
            break;
        }
    }
    if (!exist) cout << "-1";
    return 0;
}