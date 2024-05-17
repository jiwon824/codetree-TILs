#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    int cnt =0;
    sort(arr, arr+3);

    while(true){
        int diff1=abs(arr[0]-arr[1]), diff2=abs(arr[1]-arr[2]);
        // 이미 연속인 경우
        if(diff1==1 && diff2==1) break;
        // 하나만 옮기면 되는 경우
        if(diff1==2 || diff2==2){
            cnt++;
            break;
        }

        // 2번 이상 움직임이 필요한 경우
        if(diff1==1 || diff2==1){
            // 3 4 7 / 3 6 7처럼 2개가 붙어 있는 경우
            if(diff1==1){
                // 3 4 7과 같은 경우
                // 4와 3을 swap한 후 3을 5로 변경한다
                int tmp = arr[2]-2; // arr[0]을 arr[2]-2로 변경후 swap과 동일
                arr[0]= arr[1];
                arr[1]= tmp;
            }
            else{
                // 3 6 7의 경우
                int tmp = arr[0]+2; // arr[2]을 arr[0]+2로 변경후 swap과 동일
                arr[2]= arr[1];
                arr[1]= tmp;
            }
        }
        else{
            // 2 6 9처럼 사이로 이동할 수 있는 경우
            int tmp = arr[2]-2; // arr[0]을 arr[2]-2로 변경후 swap과 동일
            arr[0]= arr[1];
            arr[1]= tmp;
        }

        cnt++;
    }
    cout << cnt <<'\n';
    return 0;
}