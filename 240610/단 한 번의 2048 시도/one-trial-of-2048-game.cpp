#include <iostream>

using namespace std;

int arr[4][4];
char dir; // ‘L', ‘R’, ‘U’, 'D’ 

// Shift Func
void LeftShift(){
    for(int row=0; row<4; row++){
        int endOfIdx=-1;
        // 0찾기
        for(int col=0; col<4; col++){
            if(arr[row][col]==0){
                endOfIdx=col;
                break;
            }
        }
        if(endOfIdx==-1) continue; // 0이 없으면 shift x

        // shift
        for(int col=endOfIdx+1; col<4; col++){
            if(arr[row][col]!=0){
                arr[row][endOfIdx]=arr[row][col];
                arr[row][col]=0;
                endOfIdx++;
            }
        }
    }
}
void RightShift(){
    for(int row=0; row<4; row++){
        int endOfIdx=-1;
        // 0찾기
        for(int col=3; col>=0; col--){
            if(arr[row][col]==0){
                endOfIdx=col;
                break;
            }
        }
        if(endOfIdx==-1) continue; // 0이 없으면 shift x

        // shift
        for(int col=endOfIdx-1; col>=0; col--){
            if(arr[row][col]!=0){
                arr[row][endOfIdx]=arr[row][col];
                arr[row][col]=0;
                endOfIdx--;
            }
        }
    }
}
void UpShift(){
    for(int col=0; col<4; col++){
        int endOfIdx=-1;
        // 0찾기
        for(int row=0; row<4; row++){
            if(arr[row][col]==0){
                endOfIdx=row;
                break;
            }
        }
        if(endOfIdx==-1) continue; // 0이 없으면 shift x

        // shift
        for(int row=endOfIdx+1; row<4; row++){
            if(arr[row][col]!=0){
                arr[endOfIdx][col]=arr[row][col];
                arr[row][col]=0;
                endOfIdx++;
            }
        }
    }
}
void DownShift(){
    for(int col=0; col<4; col++){
        int endOfIdx=-1;
        // 0찾기
        for(int row=3; row>=0; row--){
            if(arr[row][col]==0){
                endOfIdx=row;
                break;
            }
        }
        if(endOfIdx==-1) continue; // 0이 없으면 shift x
        // shift
        for(int row=endOfIdx-1; row>=0; row--){
            if(arr[row][col]!=0){
                arr[endOfIdx][col]=arr[row][col];
                arr[row][col]=0;
                endOfIdx--;
            }
        }
    }
}
void Shift(){
    if(dir=='L') LeftShift();
    else if(dir=='R') RightShift();
    else if(dir=='U') UpShift();
    else DownShift();
}

//Combine Func
void LeftCombine(){
    for(int row=0; row<4; row++){
        for(int col=0; col<3; col++){
            if(arr[row][col]==arr[row][col+1]){
                arr[row][col]*=2;
                arr[row][col+1]=0;
            }
        }
    }  
}
void RightCombine(){
    for(int row=0; row<4; row++){
        for(int col=3; col>0; col--){
            if(arr[row][col]==arr[row][col-1]){
                arr[row][col]*=2;
                arr[row][col-1]=0;
            }
        }
    }
}
void UpCombine(){
    for(int col=0; col<4; col++){
        for(int row=0; row<3; row++){
            if(arr[row][col]==arr[row+1][col]){
                arr[row][col]*=2;
                arr[row+1][col]=0;
            }
        }
    }
}
void DownCombine(){
    for(int col=0; col<4; col++){
        for(int row=3; row>0; row--){
            if(arr[row][col]==arr[row-1][col]){
                arr[row][col]*=2;
                arr[row-1][col]=0;
            }
        }
    }
}
void Combine(){
    if(dir=='L') LeftCombine();
    else if(dir=='R') RightCombine();
    else if(dir=='U') UpCombine();
    else DownCombine();
}

int main() {
    //input
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }
    cin >> dir;
    
    //solution
    Shift();
    Combine();
    Shift();

    //output
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout <<'\n';
    }
    return 0;
}