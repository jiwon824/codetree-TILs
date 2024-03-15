#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >>n>>m;
    int* numbers = new int[n];
    for(int i=0;i<n;i++){
        cin >>numbers[i];
    }
    int answer =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(numbers[i]+numbers[j]==m) answer++;
        }
    }
    cout << answer;
    return 0;
}