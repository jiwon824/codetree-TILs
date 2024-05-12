#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];
int n, l;

int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 내림차순으로 정렬
    sort(arr, arr+n, greater<int>());
    //for(int i=0; i<n ;i++){
    //    cout << arr[i] << " ";
    //}
    //cout <<'\n';
    
    // i이상인 수가 i개 이상 나오면 cout<< i; break; 하면 됨
    for(int i=n; i>=0; i--){
        int num_of_over_i=0, l_cnt=l;
        for(int j=0; j<n; j++){
            if(arr[j]>=i) num_of_over_i++;
            else if(arr[j]==i-1 && l_cnt>0){
                l_cnt--;
                num_of_over_i++;
            }
        }

        if (num_of_over_i>=i) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}