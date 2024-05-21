#include <iostream>

using namespace std;

int block[10001];

int main() {
    int n;
    cin >> n;
    int sum =0;
    for(int i=0; i<n; i++){
        cin >> block[i];
        sum+=block[i];
    }
    
    int avg = sum/n, answer=0;
    for(int i=0; i<n; i++){
        if(block[i]<avg) answer+=(avg-block[i]);
    }
    cout << answer << '\n';

    return 0;
}