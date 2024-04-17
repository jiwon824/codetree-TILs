#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    int num_of_people=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        num_of_people+= arr[i];
    }
    

    // Solution
    int minDist= INT_MAX;
    for (int i=0; i<n;i++){
        int dist = 0;
        for(int j=i;j<n+i;j++){
            dist= dist + (j-i)*arr[j%n];
            //cout << j%n;
        }
        //cout <<'\n';
        if(minDist>dist) minDist=dist;
    }
    cout << minDist;
    return 0;
}