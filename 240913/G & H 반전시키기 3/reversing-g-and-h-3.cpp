#include <iostream>
using namespace std;

int n;
string initStr, targetStr;

int main() {
    cin >> n;
    cin >> initStr >> targetStr;
    
    int range=1, numOfSection=0;
    for(int i=0; i<n; ){
        if(initStr[i]!=targetStr[i]){
            while(i+1<n && initStr[i]!=targetStr[i]){
                i++;
                range++;
            }
            if(range>4) {
                if(range%4==0) numOfSection+= range/4;
                else numOfSection+= range/4+1;
            }
            else numOfSection++;
        }
        range=1;
        i++;
    }

    cout << numOfSection << '\n';
    return 0;
}