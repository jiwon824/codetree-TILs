#include <iostream>

using namespace std;
void PrintStar(int n){
    if(n==0) return;
    for(int i=0;i<n;i++){
        cout << "* ";
    }
    cout <<'\n';
    PrintStar(n-1);
    for(int i=0;i<n;i++){
        cout << "* ";
    }
    cout <<'\n';

}
int main() {
    int n;
    cin >>n;
    PrintStar(n);
    return 0;
}