#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    string first_word, second_word;
    cin >> first_word >> second_word;

    if(first_word.length()!=second_word.length()){
        cout <<"No";
        return 0;
    }

    sort(first_word.begin(), first_word.end());
    sort(second_word.begin(), second_word.end());

    bool isAnswer= true;
    for(int i=0; i<first_word.length(); i++){
        if(first_word[i]!=second_word[i]) {
            isAnswer =false;
            break;
        }
    }
    if(isAnswer) cout << "Yes";
    else cout <<"No";
    return 0;
}