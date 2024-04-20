#include <iostream>

using namespace std;
int people[10001];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int pos;
        char alpha;
        cin >> pos >> alpha;
        if(alpha=='G') people[pos-1] = 1;
        else people[pos-1] = 2;
    }

    int answer =0;
    for(int i=0;i<=10001-k;i++){
        int sum =0;
        for(int j=i; j<=i+k;j++){
            sum+=people[j];
        }
        if(answer<sum) answer=sum;
    }
    cout << answer;
    return 0;
}