#include <iostream>

using namespace std;

bool isInteresting(int num){
    //cout << num <<'\n';
    int num_of_numbers[10] ={0, };

    while(num){
        num_of_numbers[num%10]++;
        num/=10;
    }

    int num_of_diff =0;
    for(int i=0; i<10; i++){
        if(num_of_numbers[i]==1) num_of_diff++;
    }
    if(num_of_diff==1) return true;
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