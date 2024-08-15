#include <iostream>
#define MAX_N 100001
using namespace std;

char info[MAX_N];
int lHSP[3][MAX_N]; // 0H 1S 2P
int rHSP[3][MAX_N]; // 0H 1S 2P


int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> info[i];
    }

    // L 배열 채우기
    for(int i=0; i<n; ++i){
        if(info[i]=='H'){
            lHSP[0][i] = lHSP[0][i-1]; // 비김
            lHSP[1][i] = lHSP[1][i-1]; //짐
            lHSP[2][i] = lHSP[2][i-1]+1; // 이김
        }
        else if(info[i]=='S'){
            lHSP[0][i] = lHSP[0][i-1]+1; // 이김
            lHSP[1][i] = lHSP[1][i-1]; // 비김
            lHSP[2][i] = lHSP[2][i-1]; // 짐
        }
        else{
            lHSP[0][i] = lHSP[0][i-1]; // 짐
            lHSP[1][i] = lHSP[1][i-1]+1; // 이김
            lHSP[2][i] = lHSP[2][i-1]; // 비김
        }
    }

    // R 배열 채우기
    for(int i=n-1; i>=0; --i){
        if(info[i]=='H'){
            rHSP[0][i] = rHSP[0][i+1]; // 비김
            rHSP[1][i] = rHSP[1][i+1]; //짐
            rHSP[2][i] = rHSP[2][i+1]+1; // 이김
        }
        else if(info[i]=='S'){
            rHSP[0][i] = rHSP[0][i+1]+1; // 이김
            rHSP[1][i] = rHSP[1][i+1]; // 비김
            rHSP[2][i] = rHSP[2][i+1]; // 짐
        }
        else{
            rHSP[0][i] = rHSP[0][i+1]; // 짐
            rHSP[1][i] = rHSP[1][i+1]+1; // 이김
            rHSP[2][i] = rHSP[2][i+1]; // 비김
        }
    }

    // 이길 수 있는 최대 게임 수
    int answer=0;
    for(int i=0; i<n; ++i){
        int hsp1 = max(lHSP[0][i]+rHSP[1][i+1], lHSP[0][i]+rHSP[2][i+1]);
        int hsp2 = max(lHSP[1][i]+rHSP[0][i+1], lHSP[1][i]+rHSP[2][i+1]);
        int hsp3 = max(lHSP[2][i]+rHSP[0][i+1], lHSP[2][i]+rHSP[1][i+1]);
        answer=max(answer, max(hsp1, max(hsp2, hsp3)));
    }
    cout << answer <<'\n';
    return 0;
}