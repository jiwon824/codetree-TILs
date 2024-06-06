#include <iostream>

using namespace std;

int n;
int blocks[101]={-1, };// 1<=blocks[i]<=100

void RemoveBlocks(int start, int end){
    // 제거
    for(int i=start; i<=end; i++){
        blocks[i]=0;
    }

    // 앞으로 당기기
    int endOfArr=start;
    for(int i=start; i<n; i++){
        if(blocks[i]!=0){
            blocks[endOfArr]=blocks[i];
            blocks[i]=0;
            endOfArr++;
        }
    }
    
    n-=(end-start+1);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> blocks[i];
    }
    int s, e;
    cin >> s >> e;
    RemoveBlocks(s-1, e-1);
    cin >> s >> e;
    RemoveBlocks(s-1, e-1);


    // output
    cout << n << '\n'; // 남은 블록의 갯수
    for(int i=0; i<n; i++){
        cout << blocks[i] <<'\n'; // 남은 블록에 적힌 숫자들
    }

    return 0;
}