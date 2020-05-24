#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int parse(istringstream& ss) {
    string token;
    getline(ss, token, ' ');
    return token[0] - '0';
}

int main() {
    ios::sync_with_stdio(false);
    
    map<string, int> mp;
    mp["A"] = 1;
    mp["C"] = 1;
    mp["B"] = 2;
    mp["D"] = 2;

    string turn;
    int whoHasStarted = false;
    int totalW = 0, totalB = 0;
    int whoGotRed = 0;
    
    while(getline(cin, turn)) {
        if (turn == "#") {
            bool gotWinner = false;
            if (whoGotRed && whoHasStarted) {
                if (whoGotRed == whoHasStarted) {
                    if (totalW == 9) {
                        gotWinner = true;
                        cout << "Team-" << whoGotRed << " win and the point is " << 5 + 9 - totalB << "." << '\n';
                    }
                } else {
                    if (totalB == 9) {
                        gotWinner = true;
                        cout << "Team-" << whoGotRed << " win and the point is " << 5 + 9 - totalW << "." << '\n';
                    }
                }
            }
            if (!gotWinner) {
                cout << "Incomplete game." << '\n';
            }
            whoHasStarted = 0;
            totalB = 0;
            totalW = 0;
            whoGotRed = 0;
        } else {
            istringstream ss(turn);
            string playerID;
            getline(ss, playerID, ' ');
            int W = parse(ss);
            int B = parse(ss);
            int R = parse(ss);
            if (whoHasStarted == 0) {
                whoHasStarted = mp[playerID];
            }
            totalW += W;
            totalB += B;
            if (R == 1) {
                whoGotRed = mp[playerID];
            }
        }
    }
    
    return 0;
}