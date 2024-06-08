#include <iostream>

using namespace std;

int n, m;
int bombs[101]; // 1이상 100이하의 숫자가 적혀있는 N개의 폭탄

// 배열의 원소들을 앞으로 당기는 
void MakeCompact(){
    // 빈 공간 찾기
    int endOfIdx=0;
    for(int i=0; i<n; i++){
        if(bombs[i]==0) {
            endOfIdx=i;
            break;
        }
    }

    // 원소들 앞으로 당기기
    for(int i=endOfIdx; i<n; i++){
        if(bombs[i]!=0){
            bombs[endOfIdx]=bombs[i];
            bombs[i]=0;
            endOfIdx++;
        }
    }
    
    // 배열 갯수 세기
    n=endOfIdx;
}

bool IsExploding(){
    bool isExplode=false;

    int cnt=1;
    // 폭발될 숫자가 있나 확인
    for(int i=1; i<n; i++){
        if(bombs[i-1]==bombs[i]) cnt++;
        else cnt=1;
        if(cnt>=m){
            isExplode = true;
            break;
        }
    }
    return isExplode;
}

// m개 이상 연속 같은 숫자가 있으면 해당 숫자 폭탄이 전부 터짐
void Explode(){
    while (true){
        if(m==1) {
            n=0;
            break;
        }
        if(!IsExploding()) break;

        //M개 이상인 폭탄들의 쌍이 여러 개라면 동시에 터지게 됩니다.
        int cnt=1, sIdx=0;
        for(int i=1; i<n; i++){
            if (bombs[i]==0) continue;
            if (bombs[i-1]==bombs[i]) cnt++;
            else {
                cnt=1;
                sIdx=i;
            }

            if(cnt>=m){
                int removeNum=bombs[sIdx];
                for(int j=sIdx; j<n; j++){
                    if(bombs[j]!=removeNum) break;
                    bombs[j]=0;
                }
            }
        }

        MakeCompact();
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