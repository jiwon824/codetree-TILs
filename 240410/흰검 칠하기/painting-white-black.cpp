#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[200000] ={0, };

    int num_of_black[200000]={0, };
    int num_of_white[200000]={0, };
    char color[200000]; //마지막으로 저장된 색

    int pos = 100000; // 1000*100

    // x L = 왼쪽으로 이동하면서 **현재 위치 타일포함 총 x칸의 타일**을 흰색으로 연속하게 칠하고
    // x R = 오른쪽으로 이동하면서 **현재 위치 타일포함 총 x칸의 타일**을 검은색으로 연속하게 칠함
    // 덧칠하면 마지막으로 칠한 색으로 바뀜
    // 순서 상관없이 흰색과 검은색으로 각각 두 번 이상 칠해지면 회색으로 바뀌고 더 이상 바뀌지x
    for (int i=0; i<n; i++){
        int x;
        char dir;
        cin >> x >> dir;
        
        if (x==1){
            arr[pos]++;
            if (dir=='L'){
                num_of_white[pos]++;
                color[pos] = 'W';
            }
            else{
                num_of_black[pos]++;
                color[pos]= 'B';
            }
        }
        else{
            if (dir=='L'){
                for(int j=pos-x+1;j<=pos;j++){
                    //cout << j-100000 <<'\n';
                    arr[j]++;
                    num_of_white[j]++;
                    color[j] = 'W';
                }
                pos = pos-x+1; // 현재위치 포함이라서 +1한 값만큼 왼쪽으로 가야함
            }
            else {
                for(int j=pos;j<pos+x;j++){
                    //cout << j-100000 <<'\n';
                    arr[j]++;
                    num_of_black[j]++;
                    color[j]= 'B';
                }
                pos = pos+x-1; // 현재위치 포함이라서 -1한 값만큼 오른쪽으로 가야함
            }
        }
        //cout << x << " " << dir << ", pos: " << pos-100000 <<'\n';
    }

    // 색깔 세기
    int white = 0, black = 0, gray = 0;

    //cout << "result\n";
    for (int i =0; i<200000; i++){
        /*
        if (arr[i]!=0) {
            cout << i-100000 << " "<< arr[i];
            cout << ",  black[i]"<< num_of_black[i];
            cout << ", white[i]" << num_of_white[i]<<'\n';
        } 
        */
        if(num_of_black[i]>=2 && num_of_white[i]>=2) gray++;
        else if(color[i]=='B') black++;
        else if(color[i]=='W') white++;
        /* 흰2 이상 + 검2 이상이어야 해서 흰흰흰흰 이렇게 될 경우를 잡지 못함
                if(arr[i]>0 && arr[i]<4){
                    if (color[i]=='B') {
                        black++;
                    }
                    else white++;
                }
                else if (arr[i]>=4){
                    gray++;
                }
        */
    }
    cout << white << " " << black << " " << gray;
    return 0;
}