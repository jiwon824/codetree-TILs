#include <iostream>

using namespace std;

// 홀수+홀수=짝수 1+1=2, 3+5=8, 13+19=32
// 홀수+짝수=홀수 1+2=3, 3+6=9, 13+20=33
// 짝수+짝수=짝수 2+2=4, 6+8=14, 14+20=34

int arr[1001];


int Cnt_Bundles(int odd, int even){
    int answer =0;
    
    if(even > odd) answer = odd*2+1;
    else if(even == odd) answer = even+odd;
    else{
        // odd>even 홀수가 짝수보다 많음
        answer=even*2;
        int size = odd-even;
        if(size%3==0){
            answer +=size/3 *2;
        }
        else{
            if((size%3)%2==0) answer+= (size/3*2+1);
            else answer+= (size/3*2-1);
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    int odd_num=0, even_num=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i]%2==0) even_num++;
        else odd_num++;
    }
    
    cout << Cnt_Bundles(odd_num, even_num);

    return 0;
}