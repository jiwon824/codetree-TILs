#include <iostream>

using namespace std;

int arr[27];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char alpha;
        cin >>alpha;
        arr[i]=alpha-'A'; // 영어를 숫자로 바꿔서 arr에 저장
    }
    
    int cnt =0;
    // i번째에 i가 있어야 함
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // arr[j]가 i번째에 있다면 
            if(arr[j]==i) {
                // 이동시키기
                for(int k=j; k>i; k--){
                    int tmp =arr[k];
                    arr[k]=arr[k-1];
                    arr[k-1]=tmp;
                }
                cnt += (j-i);
            }
        }
    }
    cout << cnt;
    return 0;
}