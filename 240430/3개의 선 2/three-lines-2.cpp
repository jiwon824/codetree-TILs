#include <iostream>

using namespace std;

int coordinates[21][2];

int main() {
    int n;
    cin >> n;
    //x축 혹은 y축에 평행한 직선 3개가 주어진 모든 점을 전부 지날 수 있는지 판단
    for(int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
    }
    
    int answer = 0;
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            for(int k=0; k<=10; k++){
                bool isAnswer = true;
                for(int l=0; l<n; l++){
                    if(coordinates[l][0]==i || coordinates[l][0]==j ||coordinates[l][0]==k) isAnswer=true;
                    else if(coordinates[l][1]==i || coordinates[l][1]==j ||coordinates[l][1]==k) isAnswer=true;
                    else isAnswer = false;
                }
                if(isAnswer) answer=1;
            }
        }
    }
    cout << answer;
    return 0;
}