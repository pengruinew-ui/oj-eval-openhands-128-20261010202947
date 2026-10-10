#include <bits/stdc++.h>
using namespace std;

bool win(const vector<string>& b, char p) {
    // rows
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p) return true;
    }
    // cols
    for (int j = 0; j < 3; ++j) {
        if (b[0][j] == p && b[1][j] == p && b[2][j] == p) return true;
    }
    // diags
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p) return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        if(!(cin >> board[i])) return 0;
        if(board[i].size()!=3){
            cout << "invalid";
            return 0;
        }
    }
    int cntX=0,cntO=0,cntDash=0;
    for (auto &row: board) {
        for(char c: row){
            if(c=='x') cntX++;
            else if(c=='o') cntO++;
            else if(c=='-') cntDash++;
            else {
                cout << "invalid";
                return 0;
            }
        }
    }
    // basic count validity
    if(!(cntX==cntO || cntX==cntO+1)){
        cout << "invalid";
        return 0;
    }
    bool xWin = win(board,'x');
    bool oWin = win(board,'o');
    if(xWin && oWin){
        cout << "invalid";
        return 0;
    }
    if(xWin){
        if(cntX!=cntO+1){
            cout << "invalid";
        } else {
            cout << "win";
        }
        return 0;
    }
    if(oWin){
        if(cntX!=cntO){
            cout << "invalid";
        } else {
            cout << "lose";
        }
        return 0;
    }
    // no winner
    if(cntDash==0){
        cout << "tie";
    } else {
        cout << "ongoing";
    }
    return 0;
}
