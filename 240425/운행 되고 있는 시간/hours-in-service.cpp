#include <iostream>
#define MAX_N 101
#define MAX_TIME 1001
using namespace std;

int work_time[MAX_N][2]; // 각 직원의 출근/퇴근시간

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> work_time[i][0] >> work_time[i][1];
    }
    
    int max_runtime =0;
    for(int i=0; i<n; i++){
        int hours_of_operation[MAX_TIME] ={0, }; // 운영시간을 보기 위한 배열
        for(int j =0; j<n; j++){
            if(i==j) continue; // i번째 사원을 뺐을 때 운행되고 있는 시간을 구할 거기 때문에 continue
            
            // j 사원이 일하는 시간 체크
            for(int k =work_time[j][0]; k<work_time[j][1]; k++){
                hours_of_operation[k]++;
            }
        }
        
        // 운영시간 체크
        int runtime=0;
        for(int j=0; j<MAX_TIME; j++){
            if(hours_of_operation[j]>0) runtime++; 
        }
        //cout << runtime <<'\n';
        if(max_runtime<runtime) max_runtime=runtime;
    }
    cout << max_runtime;

    return 0;
}