#include <iostream>

using namespace std;

int residency_status[101];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> residency_status[i];
    }

    int wifi[101]={0, };
    int cnt=0;
    for(int i=0; i<n; i++){
        if(residency_status[i]==1 && wifi[i]==0){
            for(int j=i; j<=i+2*m; j++){
                if(j<0 || j>=n) continue;
                wifi[j]=1;
            }
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}