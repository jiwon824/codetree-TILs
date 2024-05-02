#include <iostream>

using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    
    int answer=-1;
    for(int i=0; i<a.length(); i++){
        string new_a = "";
        for(int j=i; j<a.length();j++){
            new_a = new_a + a[j];
        }
        for(int j=0; j<i; j++){
            new_a = new_a + a[j];
        }

        if(new_a==b) answer = i;
    }
    cout << answer;
    return 0;
}