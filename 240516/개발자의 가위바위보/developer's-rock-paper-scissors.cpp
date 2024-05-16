#include <iostream>
#include <algorithm>

using namespace std;

int rps[101][2];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> rps[i][0] >> rps[i][1];
    }

    //cases (1==4==5) (2==3==6) 사실상 2가지 경우
        //1 [1]가위 [2]바위 [3]보
            // a=1 b=3
            // a=2 b=1
            // a=3 b=2
        //2 [1]가위 [2]보 [3]바위
            // a=1 b=2
            // a=2 b=3
            // a=3 b=1
        //3 [1]바위 [2]가위 [3]보
            // a=1 b=2
            // a=2 b=3
            // a=3 b=1
        //4 [1]바위 [2]보 [3]가위
            // a=1 b=3
            // a=2 b=1
            // a=3 b=2
        //5 [1]보 [2]가위 [3]바위
            // a=1 b=3
            // a=2 b=1
            // a=3 b=2
        //6 [1]보 [2]바위 [3]가위
            // a=1 b=2
            // a=2 b=3
            // a=3 b=1
    int cases[2]={0, };
    for(int i=0; i<n; i++){
        int first=rps[i][0], second=rps[i][1];
        if((first==1 && second==3) || (first==2 && second==1) || (first==3 &&second==2))cases[0]++;
        else if((first==1 && second==2) || (first==2 && second==3) || (first==3 &&second==1))cases[1]++;
    }
    cout << max(cases[0], cases[1])<<'\n';
    return 0;
}