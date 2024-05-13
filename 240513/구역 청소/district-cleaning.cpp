#include <iostream>

using namespace std;
int arr[101];
int main() {
    int a, b, c, d;
    cin >>a >> b>> c>> d;
    for(int i=a; i<b; i++){
        arr[i]++;
    }
    for(int i=c;i<d;i++){
        arr[i]++;
    }

    int answer=0;
    for(int i=0; i<101;i++){
        if(arr[i]>0) answer++;
    }
    cout << answer;
    return 0;
}