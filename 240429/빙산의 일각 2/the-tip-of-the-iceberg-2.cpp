#include <iostream>

using namespace std;

int height[101];
int main() {
    int n;
    cin >> n;
    int max_height=0;
    for(int i=0; i<n; i++){
        cin>> height[i];
        if(max_height<height[i]) max_height = height[i];
    }

    // 높이가 i일 때 빙산 덩어리의 최대갯수 answer
    int answer =0;
    for(int i=1; i<=max_height; i++){
        //cout << "높이는 "<< i << '\n';
        int num_of_ice =0;
        for(int j=1; j<n; j++){
            int prev_ice = height[j-1]-i;
            int curr_ice = height[j]-i;

            if(prev_ice>=1 && curr_ice<=0){
                //cout << "조건1 " << j-1 << " " << j <<'\n';
                //cout << prev_ice << " " <<curr_ice <<'\n';
                num_of_ice++;
            }
            //else if(prev_ice<=0 && curr_ice>=1){
            //    cout << "조건2 " << j-1 << " " << j <<'\n';
            //    cout << prev_ice << " " <<curr_ice <<'\n';
            //    num_of_ice++;
            //}
        }
        if(height[n-1]-i >=1) num_of_ice++;
        //cout << "높이가 " << i << "일 때 빙산의 갯수 " << num_of_ice << '\n'; 
        if(answer<num_of_ice) answer= num_of_ice;
    }
    cout << answer;
    return 0;
}