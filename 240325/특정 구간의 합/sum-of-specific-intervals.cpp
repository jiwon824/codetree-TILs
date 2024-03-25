#include <iostream>
using namespace std;

int n, m;
int *arr = new int[n];
void Sum(int n, int m){
    int sum =0;
    for(int i=n; i<=m;i++){
        sum +=arr[i];
    }
    cout << sum << '\n';
}
int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        Sum(a-1, b-1);
    }
    return 0;
}