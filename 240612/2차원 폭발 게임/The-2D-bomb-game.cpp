#include <iostream>

using namespace std;

int n, m ,k;// m개 이상
int arr[101][101];

void Roatate(){
    int tmp[101][101]={0, };
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            tmp[col][n-row-1]=arr[row][col];
        }
    }

    // tmp를 다시 arr에 복사
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=tmp[i][j];
        }
    }
}

void Drop(){
    for(int col=0; col<n; col++){
        // col번째 열에서 가장 아래 행에 있는 0 찾기
        int endOfIdx = -1;
        for(int row=n-1; row>0; row--){
            if(arr[row][col]==0) {
                endOfIdx=row;
                break;
            }
        }
        // 0이 없는 열이라면 그냥 넘어가기
        if(endOfIdx==-1) continue;

        // Swap
        for(int row=endOfIdx-1; row>=0; row--){
            if(arr[row][col]!=0){
                arr[endOfIdx][col]= arr[row][col];
                arr[row][col]=0;
                endOfIdx--;
            }
        }
    }
}

void Explode(){
    for(int col=0; col<n; col++){
        int cnt=1;
        for(int row=0; row<n-1; row++){
            if(arr[row][col]==arr[row+1][col]) {
                cnt++;
                continue;
            }

            if(cnt>=m){
                for(int idx=row-cnt+1; idx<=row; idx++){
                    arr[idx][col]=0;
                }
            }
            cnt=1;
        }

        if(cnt>=m){
            for(int idx=(n-1)-cnt+1; idx<=n-1; idx++){
                arr[idx][col]=0;
            }
        }
    }
}

bool PossibleToExplode(){
    for(int col=0; col<n; col++){
        int cnt=1;
        for(int row=n-1; row>=0; row--){
            if(arr[row][col]==0 || row-1<0) break;

            if(arr[row][col]==arr[row-1][col]) cnt++;
            else cnt=1;

            if(cnt>=m) return true;
        }
    }
    return false;
}
void PrintArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] <<" ";
        }
        cout <<'\n';
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    // solution
    if(m==1){
        cout << 0 <<'\n';
        exit(0);
    }

    for(int i=0; i<k; i++){
        while(PossibleToExplode()){
            Explode();
            Drop();
        }


        Roatate();
        Drop();

        while(PossibleToExplode()){
            Explode();
            Drop();
        }
    }

    // output
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]!=0) answer++;
        }
    }
    cout << answer<<'\n';
    return 0;
}