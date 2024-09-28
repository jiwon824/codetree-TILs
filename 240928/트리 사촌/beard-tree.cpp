#include <iostream>
#include <vector>

using namespace std;

const int MAX_N= 1001;
const int MAX_NODE= 1000001;

int n, k, p;
int sequences[MAX_N]; // input으로 주어지는 증가하는 수열
int numOfChild[MAX_NODE]; // i번 노드의 자식의 개수
int parent[MAX_NODE]; // parent[i]: i번 노드의 부모 번호

void MakeTree(){
    p=0;
    for(int i=1; i<n; ++i){
        // 연속하는 경우
        if(i+1<n && sequences[i]+1==sequences[i+1]){
            parent[sequences[i]]=sequences[p];
            numOfChild[sequences[p]]++;
        }
        else{
            parent[sequences[i]]=sequences[p];
            numOfChild[sequences[p]]++;
            p++;
        }
    }
}

// return num of cousin node
int GetCousinNode(){
    int cnt=0;
    bool visited[MAX_NODE]={false, };
    for(int i=0; i<MAX_NODE; ++i){
        // 부모가 다르지만 두 부모가 형제인 경우(=부모의 부모가 같은 경우)
        if(parent[i]!=parent[k] && parent[parent[k]]==parent[parent[i]]){
            //cnt++;
            // 8, 9의 부모는 둘 다 3
            // 3의 자식 수를 8에서 더하고, 9에서 또 더하면 안 된다.
            if(!visited[parent[i]]){
                cnt+=numOfChild[parent[i]];
                visited[parent[i]]=true;
            }
        }
    }
    return cnt;
}

int main() {
    // input
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> sequences[i];
    }

    MakeTree();

    cout << GetCousinNode() << '\n';
    return 0;
}