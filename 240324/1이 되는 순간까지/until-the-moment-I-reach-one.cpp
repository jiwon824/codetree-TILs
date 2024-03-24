#include <iostream>

using namespace std;
int answer = 0;
int Solution(int n){
    if(n==1) return answer;
    answer++;
    if(n%2==0) return Solution(n/2);
    else return Solution(n/3);
}
int main() {
    int n;
    cin >> n;
    cout << Solution(n);
    return 0;
}