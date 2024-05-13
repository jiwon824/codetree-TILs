#include <iostream>

using namespace std;

int lines[101][2];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> lines[i][0] >> lines[i][1];
    }

    for(int i=0; i<n; i++){
        bool isOverlap = false;
        int check[101]={0, };
        for(int j=0; j<n; j++){
            //i번째 선분을 빼고 비교
            if(i==j) continue;
            for(int k=lines[j][0]; k<=lines[j][1];k++){
                check[k]++;
            }
            //if(lines[j][1]<lines[j-1][0] || lines[j-1][1]<lines[j][0]) {
            //    isOverlap = false;
            //    break;
            //}

        }
        for(int j=0; j<101; j++){
            if(check[j]>=n-1) isOverlap = true;
        }
        if(isOverlap){
            cout<< "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}