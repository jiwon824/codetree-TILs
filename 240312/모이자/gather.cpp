#include <iostream>

using namespace std;
int main() {
    int n;
    cin >>n;
    int* house = new int[n];
    for (int i =0;i<n;i++){
        cin >> house[i];
    }

    int answer=10000;
    for(int i =0;i<n;i++){
        int tmp=0;
        for(int j=0;j<n;j++){
            tmp += house[j]*abs(j-i);
        }
        if (tmp<answer) answer=tmp;
        //cout<<"i: "<<i <<", tmp: "<<tmp<<", answer: "<< answer<<'\n';
    }
    cout << answer;
    return 0;
}