#include <iostream>

using namespace std;

int n, m;
int num_pair[101][2];

int Appearance(int a, int b){
    int cnt=0;
    for(int i=0; i<m; i++){
        if((num_pair[i][0]==a ||num_pair[i][0]== b)
         &&(num_pair[i][1]==a ||num_pair[i][1]== b)) cnt++;
    }
    return cnt;
}


int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> num_pair[i][0] >> num_pair[i][1];
    }
    
    int answer =0;
    // a!=b라는 조건이 있었으니까 j=i+1이라고 해도 됨
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int appear = Appearance(i, j);
            if(answer<appear) answer = appear;
        }
    }
    cout << answer;

    return 0;
}