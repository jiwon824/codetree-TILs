#include <iostream>
#include <vector>
using namespace std;

vector<int> bomb_type;
int arr[21][21];

int n; // arr 크기
int num_of_bomb; // arr에 설치된 폭탄의 갯수
int answer;

// 만들어진 bomb_type을 바탕으로 폭발구역의 갯수를 반환
int Check_Exploding_zones(){
    // bomb_type ={1, 2, 3, 1} 이라면
    // 역순(1, 3, 2, 1)으로 배치하면서 pop_back하는 형식으로 구현(어차피 모든 조합이 들어있을 것이기 때문에 뒤집어도 상관없음)
    vector<int> v = bomb_type;
    int exploding_map[21][21] ={0, };

    // arr를 돌기 위한 이중 포문
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0) continue;
            // 폭탄을 설치할 위치라면 설치할 폭탄의 종류를 조합에서 꺼낸다.
            int exploding_type = v.back();
            v.pop_back();
            
            if(exploding_type==1){
                for(int k = i-2; k<=i+2; k++){
                    if(k<0 || k>=n) continue;
                    exploding_map[k][j]=1;
                }
            }
            else if(exploding_type==2){
                exploding_map[i][j]=1;
                if(i-1>=0) exploding_map[i-1][j]=1; //상
                if(i+1<n) exploding_map[i+1][j]=1; // 하
                if(j-1>=0) exploding_map[i][j-1]=1; // 좌
                if(j+1<n) exploding_map[i][j+1]=1; // 우
            }
            else{
                exploding_map[i][j]=1;
                if(i-1>=0){
                    if(j-1>=0) exploding_map[i-1][j-1]=1; //좌상
                    if(j+1<n) exploding_map[i-1][j+1]=1; //우상
                }
                if(i+1<n){
                    if(j-1>=0) exploding_map[i+1][j-1]=1; //좌하
                    if(j+1<n) exploding_map[i+1][j+1]=1; //우하
                }
            }
            
        }
    }

    int num_of_exploding=0;
    // exploding_map을 돌면서 폭발 구역의 갯수를 구함
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout << exploding_map[i][j]<<' ';
            if(exploding_map[i][j]==1) num_of_exploding++;
        }
        //cout <<'\n';
    }
    return num_of_exploding;
}

// 폭탄타입의 조합을 구하는 함수
void Make_Bomb_Combination(int bomb){
    // 종료 조건
    if(bomb>=num_of_bomb){
        //cout << "bomb_type: ";
        //for (auto e : bomb_type){
        //    cout << e << " ";
        //}
        //cout <<'\n';
        int exploding = Check_Exploding_zones();
        if(answer<exploding) answer=exploding;
        return;
    }
    // 재귀 호출
    for(int i=1; i<=3; i++){
        bomb_type.push_back(i);
        Make_Bomb_Combination(bomb+1);
        bomb_type.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1) num_of_bomb++;
        }
    }
    //cout << num_of_bomb <<'\n';
    
    Make_Bomb_Combination(0);
    cout << answer;
    return 0;
}