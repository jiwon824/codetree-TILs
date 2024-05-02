#include <iostream>

using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    
    int answer=-1;
    for(int i=0; i<a.length(); i++){
        string new_a = "";

        for(int j=a.length()-1; j>a.length()-1-i; j--){
            new_a = a[j] + new_a;
        }

        for(int j=0; j<a.length()-i; j++){
            new_a = new_a + a[j];
        }
        //cout << new_a<<'\n';

        if(new_a==b) {
            answer = i;
            break;
        }
    }
    cout << answer;
    return 0;
}