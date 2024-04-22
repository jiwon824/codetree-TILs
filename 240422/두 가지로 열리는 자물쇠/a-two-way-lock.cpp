#include <iostream>

using namespace std;

int n;
int num_of_duplicates(){

}
bool InRange(int num, int comb_num){
    // n=10일 때,
    // 1에서 거리가 2 이내인 수는 9, 10, [1], 2, 3
    // 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 
    // comb_num이 1이면 i는 -1 0, 1, 2, 3 
    // 0일 때 10, -1일 때 9가 되어야 한다. 11이면 1이 나와야 한다.
    for(int i=comb_num-2; i<=comb_num+2; i++){
        int check_num=i;
        if(i<1) check_num = n+i;
        if(i>n) check_num = i-n;
        // check_num이 num이라는 건 조합 수에서 2이내라는 것
        if(check_num ==num) return true;
    }
    return false;
}
int main() {
    cin >> n;
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    int a2, b2, c2;
    cin >> a2 >> b2 >> c2;

    int cnt =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(InRange(i, a1) && InRange(j, b1) && InRange(k, c1)) {
                    cnt++;
                    //cout << k <<'\n';
                }
                if(InRange(i, a2) && InRange(j, b2) && InRange(k, c2)) {
                    cnt++;
                    //cout << k <<'\n';
                }
                // 만약 중복이라면 cnt--
                if(InRange(i, a1) && InRange(i, a2))
                    if (InRange(j, b1) && InRange(j, b2))
                        if(InRange(k, c1) && InRange(k, c2))
                            cnt--;
                
            }
        }
    }
    cout << cnt;
    return 0;
}