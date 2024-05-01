#include <iostream>

using namespace std;

int coordinates[21][2];

int num_of_cases[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
int n;

// a, b, c는 0~10까지의 수 i, j, k
bool Check(int a, int b, int c){
    for(int i =0; i<8; i++){ // num_of_cases[i]
        bool isAnswer = true;
        //cout << "axis: "<< i <<'\n';
        for(int j=0; j<n; j++){
            //cout << (bool)(coordinates[j][num_of_cases[i][2]]==c) << '\n';
            if(coordinates[j][num_of_cases[i][0]]==a || 
               coordinates[j][num_of_cases[i][1]]==b ||
               coordinates[j][num_of_cases[i][2]]==c) continue;
            isAnswer=false; 
        }
        if(isAnswer) {
            //cout << a<< " " << b<< " " << c << '\n'; 
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    //x축 혹은 y축에 평행한 직선 3개가 주어진 모든 점을 전부 지날 수 있는지 판단
    for(int i=0; i<n; i++){
        cin >> coordinates[i][0] >> coordinates[i][1];
    }
    
    bool isAnswer;
    for(int i=0; i<=10; i++){
        for(int j=0; j<=10; j++){
            for(int k=0; k<=10; k++){
                isAnswer= Check(i, j, k);
                if(isAnswer){
                    cout << "1\n";
                    return 0;
                }
            }
        }
    }
    cout << isAnswer;
    return 0;
}