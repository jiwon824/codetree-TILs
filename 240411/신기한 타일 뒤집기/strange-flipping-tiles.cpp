#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[200000]={0, };

    int pos =100000;
    for (int i=0;i<n;i++){
        int x;
        char dir;
        cin >> x >> dir;
        if(dir =='L'){
            // 흰색=1
            for(int j=pos-x; j<pos; j++){
                arr[j]=1;
            }
            pos-=x;
        }
        else{
            // 검은색=2
            for(int j=pos; j<pos+x; j++){
                arr[j]=2;
            }
            pos+=x;
        }
    }

    //출력
    int white=0, black=0;
    for (int i=0;i<200000;i++){
        if(arr[i]==1) white++;
        else if(arr[i]==2) black++;
    }
    cout << white << " " << black;
    return 0;
}