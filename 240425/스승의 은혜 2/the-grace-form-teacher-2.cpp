#include <iostream>

using namespace std;

int gift_price[1000];
int main() {
    int n, b;
    cin >> n >> b;
    for(int i=0; i<n; i++){
        cin >> gift_price[i];
    }

    int max_gift =0;
    for(int i=0; i<n; i++){
        int num_of_gifts=0, tmp_budget=b;
        for(int j=0; j<n; j++){
            if(i==j) { // i는 쿠폰을 적용할 선물
                // j로 적어도 똑같이 기능하지만 i번째 선물에 쿠폰쓴다는 걸 표현하기 위해 i라고 적음
                if(tmp_budget<gift_price[i]/2) continue;
                tmp_budget -= gift_price[i]/2;
            }
            else{
                if(tmp_budget<gift_price[j]) continue;
                tmp_budget-=gift_price[j];
            }

            num_of_gifts++;
            if(tmp_budget==0) break;
        }
        if(max_gift < num_of_gifts) max_gift=num_of_gifts;
    }
    cout << max_gift;
    return 0;
}