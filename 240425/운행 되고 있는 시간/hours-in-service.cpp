#include <iostream>
#include <algorithm>

using namespace std;

int work_time[100][2];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> work_time[i][0] >> work_time[i][1];
    }
    
    int max_runtime =0;
    for(int i=0; i<n; i++){
        int min_start=10000, max_end=0;
        for(int j =0; j<n; j++){
            if(i==j) continue; // i번째 사원을 뺐을 때 운행되고 있는 시간을 구할 거기 때문
            if(work_time[j][0]<min_start) min_start = work_time[j][0];
            if(work_time[j][1]>max_end) max_end = work_time[j][1]; 
        }
        //cout << max_end << " " << min_start <<'\n'; 
        int runtime = max_end-min_start;
        max_runtime = max(max_runtime, runtime);
    }
    cout << max_runtime;
    return 0;
}