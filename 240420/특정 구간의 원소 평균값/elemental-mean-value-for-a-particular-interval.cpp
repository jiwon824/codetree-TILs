#include <iostream>

using namespace std;

int arr[101];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    int answer=0;
    for (int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int sum =0;
            for(int k=i; k<=j; k++){
                sum+=arr[k];
            }

            if(sum%(j-i+1) == 0){
                int avg = sum/(j-i+1);
                for(int k=i; k<=j; k++){
                    if(arr[k]==avg) {
                        answer++;
                        break;
                    }
                }

            }
        }
    }
    cout << answer;
    return 0;
}