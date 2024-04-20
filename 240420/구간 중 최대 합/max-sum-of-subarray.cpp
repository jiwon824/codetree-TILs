#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int answer =0;
    for(int i=0;i<n-k;i++){
        int sum =0;
        for(int j=i;j<k+i;j++){
            sum +=arr[j];
        }
        if(answer<sum) answer=sum;
    }
    cout << answer;
    return 0;
}