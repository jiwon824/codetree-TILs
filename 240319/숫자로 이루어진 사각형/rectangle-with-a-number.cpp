#include <iostream>

using namespace std;

void Print(int n){
    int cnt =1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << cnt <<" ";
            cnt++;
            if(cnt>9) cnt-=9;
        }
        cout <<'\n';
    }
}
int main() {
    int n;
    cin >>n;
    Print(n);
    return 0;
}