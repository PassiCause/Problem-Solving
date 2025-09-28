#include <bits/stdc++.h>
using namespace std;

vector<int> v;
char p[13];
bool checked[13];

bool check() {
    if (p[0]+p[2]+p[5]+p[7]!=22)return false;
    if (p[1]+p[2]+p[3]+p[4]!=22)return false;
    if (p[0]+p[3]+p[6]+p[10]!=22)return false;
    if (p[7]+p[8]+p[9]+p[10]!=22)return false;
    if (p[4]+p[6]+p[9]+p[11]!=22)return false;
    if (p[1]+p[5]+p[8]+p[11]!=22)return false;
    return true;
}

void print() {
    for (int i = 0; i < 12; i++) p[i] += 'A';
    cout << "...." << p[0] << "....\n";
    cout << "." << p[1] << "." << p[2] << "." << p[3] << "." << p[4] << ".\n";
    cout << ".." << p[5] << "..." << p[6] << "..\n";
    cout << "." << p[7] << "." << p[8] << "." << p[9] << "." << p[10] << ".\n";
    cout << "...." << p[11] << "....\n";
    for (int i = 0; i < 12; i++) p[i] -= 'A';
}

void backtrack(int idx) {
    if (idx == v.size()) {
        if (check()) {
            print();
            exit(0);
        }
        return;    
    }
    for (int i = 0; i < 12; i++) {
        if (!checked[i]) {
            checked[i] = true;
            p[v[idx]] = i;
            backtrack(idx + 1);
            checked[i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    char mp[5][10];
    for (int i = 0; i < 5; i++) cin >> mp[i];

    p[0]=mp[0][4]-'A';
    p[1]=mp[1][1]-'A';
    p[2]=mp[1][3]-'A';
    p[3]=mp[1][5]-'A';
    p[4]=mp[1][7]-'A';
    p[5]=mp[2][2]-'A';
    p[6]=mp[2][6]-'A';
    p[7]=mp[3][1]-'A';
    p[8]=mp[3][3]-'A';
    p[9]=mp[3][5]-'A';
    p[10]=mp[3][7]-'A';
    p[11]=mp[4][4]-'A';

    for (int i = 0; i < 12; i++) {
        if (p[i] == 'x' - 'A') {
            v.push_back(i);
        } else {
            checked[p[i]] = true;
        }
    }
    if (v.empty()) {
        print();
    } else {
        backtrack(0);
    }
}