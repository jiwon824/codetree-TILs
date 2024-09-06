#include <iostream>
using namespace std;

const int MAX_N = 100001;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int sum=0, answer=-1001;
    for(int i=0; i<n; ++i){
        if(sum<0) sum=arr[i];
        else sum+=arr[i];
        answer = max(answer, sum);
    }
    cout << answer <<'\n';
    return 0;
}