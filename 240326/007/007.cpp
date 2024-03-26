#include <iostream>
#include <string>
using namespace std;

class Agent{
    public:
        string secretCode;
        string meetingPoint;
        int time;
    Agent(string secretCode, string meetingPoint, int time){
        this->secretCode = secretCode;
        this->meetingPoint = meetingPoint;
        this->time = time;
    }
};

int main() {
    string code, place;
    int time;
    cin >> code >> place >> time;
    Agent a = Agent(code, place, time);
    cout << "secret code : " << a.secretCode<<'\n';
    cout << "meeting point : " << a.meetingPoint<<'\n';
    cout << "time : " << a.time<<'\n';

    return 0;
}