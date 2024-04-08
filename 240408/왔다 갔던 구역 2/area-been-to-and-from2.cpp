#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // L로 10칸씩 100번(n은 최대 100) 명령 = -1000
    // R로 10칸씩 100번(n은 최대 100) 명령 = 1000
    int arr[2000]={0, };
    int pos = 1000;
    for (int i=0; i<n; i++){
        int x;
        char dir;
        cin >> x >> dir;
        if(dir=='L'){
            for(int j=0;j<x;j++){
                arr[pos]++;
                pos = pos-1;
            }
        }
        if(dir=='R'){
            for(int j=0;j<x;j++){
                arr[pos]++;
                pos = pos+1;
            }
        }
    }
    int answer =0;
    for (int i=0; i<2000; i++){
        if(arr[i]>=2) {
            //cout << "i "<< i <<'\n';
            answer++;
        }
    }
    cout << answer;
    return 0;
}