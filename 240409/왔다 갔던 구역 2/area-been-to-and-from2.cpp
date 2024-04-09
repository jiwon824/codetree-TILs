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
            for(int j=pos-x; j<pos; j++){
                arr[j]++;
            }
            pos-=x;
        }
        if(dir=='R'){
            for(int j=pos;j<pos+x;j++){
                arr[j]++;
            }
            pos+=x;
        }

    }

    // 2번 이상 지나간 영역의 크기
    int answer =0;
    for (int i=0; i<2000; i++){
        if(arr[i]>=2) {
            //cout << "i "<< i << ", arr[i]" << arr[i] <<'\n';
            answer++;
        }
    }
    cout << answer;
    return 0;
}