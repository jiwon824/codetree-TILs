#include <iostream>

using namespace std;

int n, m;
int bombs[101]; // 1이상 100이하의 숫자가 적혀있는 N개의 폭탄

// 배열의 원소들을 앞으로 당기는 
void MakeCompact(int startIdx){
    // 원소들 앞으로 당기기
    for(int i=startIdx; i<n; i++){
        if(bombs[i]!=0){
            bombs[startIdx]=bombs[i];
            bombs[i]=0;
            startIdx++;
        }
    }

    // 배열 갯수 세기
    int cnt=0;
    for(int i=0; i<n; i++){
        if(bombs[i]==0) break;
        cnt++;
    }
    n=cnt;
}

int IdxToStartExploding(){
    bool isExplode=false;

    int cnt=1, idx=0;
    // 폭발될 숫자가 있나 확인
    for(int i=1; i<n; i++){
        if(bombs[i-1]==bombs[i])cnt++;
        else {
            idx=i;
            cnt=1;
        }
        if(cnt>=m){
            isExplode = true;
            break;
        }
    }

    if(isExplode) return idx;
    else return -1;
}

// m개 이상 연속 같은 숫자가 있으면 해당 숫자 폭탄이 전부 터짐
void Explode(){
    while (true){
        if(m==1) {
            n=0;
            break;
        }
        // 지울 숫자가 처음 나오는 idx
        int start=IdxToStartExploding();
        if(start==-1) break; // -1이면 지울 수가 없다는 의미
        // 지울 숫자
        int removeNum=bombs[start];
        for(int i=start; i<n; i++){
            if(bombs[i]!=removeNum) break;
            bombs[i]=0;
        }

        MakeCompact(start);
    }
}

int main() {
    // input
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> bombs[i];
    }

    // solution
    Explode();

    // output
    cout << n << '\n';
    for(int i=0; i<n; i++){
        cout << bombs[i] <<'\n';
    }

    return 0;
}