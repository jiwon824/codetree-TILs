#include <iostream>
#include <string>
using namespace std;

class Player{
    public:
        string id;
        int level;
    Player(string id ="codetree", int level=10){
        this->id=id;
        this->level=level;
    }
};
int main() {
    string id;
    int level;
    cin >> id >> level;
    Player p1 = Player();
    Player p2 = Player(id, level);
    cout << "user " << p1.id  << " lv " << p1.level <<'\n';
    cout << "user " << p2.id  << " lv " << p2.level <<'\n';
    return 0;
}