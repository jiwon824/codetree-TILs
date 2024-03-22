#include <iostream>

using namespace std;
int FindIdx(string &s1, string &s2){
    for(int i=0; i<(int)s1.size();i++){
        bool isAllSame = true;
        for(int j=i; j<i+(int)s2.size() ; j++){
            if(s1[j]!=s2[j-i]) isAllSame = false;
        }
        if(isAllSame) return i;
    }
    return -1;
}
int main() {
    string st_input, st_destination;
    cin >> st_input >> st_destination;
    cout << FindIdx(st_input, st_destination);
    return 0;
}