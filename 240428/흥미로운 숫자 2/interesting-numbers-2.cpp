#include <iostream>

using namespace std;

bool isInteresting(int num){
    //cout << "=========" << num << "=========" <<'\n';
    int num_of_numbers[10] ={0, };

    int disit =0;
    while(num){
        num_of_numbers[num%10]++;
        num/=10;
        disit++;
    }

    int num_of_diff =0;
    for(int i=0; i<10; i++){
        //cout << num_of_numbers[i] <<" ";
        if(num_of_numbers[i]==disit-1) return true;
    }
    return false;
}
int main() {
    int x, y;
    cin >> x >> y;
    
    int answer=0;
    for(int i=x; i<=y; i++){
        if(isInteresting(i)) answer++;
    }
    
    cout << answer;
    return 0;
}