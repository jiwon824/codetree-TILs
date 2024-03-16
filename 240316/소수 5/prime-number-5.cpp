#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int a, b;
    cin >> a>> b;
    bool* check = new bool[b]();
    for (int i=2;i<sqrt(b);i++){
        if(check[i]==false){
            for(int j =i*i;j<=b;j+=i) check[j] = true;
        }
    }

    int answer =0;
    for(int i=a;i<=b;i++){
        if(!check[i]) answer++;
    }
    cout << answer;
    return 0;
}