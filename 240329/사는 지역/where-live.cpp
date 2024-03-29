#include <iostream>
#include <algorithm>
using namespace std;

class Resource{
    public:
        string name, address, region;
    Resource(string name="", string address="", string region=""){
        this->name = name;
        this->address = address;
        this->region = region;
    }
    bool operator <(Resource &resource){
        return this->name >resource.name;
    }
};
int main() {
    int n;
    cin >> n;
    Resource r[10];
    for (int i=0;i<n;i++){
        string input_name, input_address, input_region;
        cin >> input_name >> input_address >> input_region;
        r[i] = Resource(input_name, input_address, input_region);
    }

    // 사전순으로 이름이 가장 느린 사람의 자료를 출력하는 프로그램
    sort(r, r+n);
    
    cout << "name " << r[0].name <<'\n';
    cout << "addr " << r[0].address <<'\n';
    cout << "city " << r[0].region <<'\n';

    return 0;
}