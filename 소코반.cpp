#include <bits/stdc++.h>
using namespace std;

int r, c, t; 
char mp[15][16], op[51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (1) {
        cin >> r >> c;
        if (r == 0 && c == 0) {
            break;
        }
        int cr, cc;
        for (int i = 0; i < r; i++) {
            cin >> mp[i];
            
            for (int j = 0; j < strlen(mp[i]); j++) {
                if (mp[i][j] == 'w' || mp[i][j] == 'W') {
                    cr = i; cc = j;
                }
            }
        }
        cin >> op;
        int fflag = 1;

        for (int i = 0; i < strlen(op); i++) {
            int nr, nc, fr, fc;
            nr = cr;
            nc = cc;
            fr = cr;
            fc = cc;
            switch (op[i]) {
                case 'U':
                    nr = cr - 1;
                    fr = nr - 1;
                    break;
                case 'D':
                    nr = cr + 1;
                    fr = nr + 1;
                    break;
                case 'L':
                    nc = cc - 1;
                    fc = nc - 1;
                    break;
                case 'R':
                    nc = cc + 1;
                    fc = nc + 1;
                    break;
            }
            switch (mp[nr][nc]) {
                case '.': case '+':
                    if (mp[cr][cc] == 'W') {
                        mp[cr][cc] = '+';
                    } else {
                        mp[cr][cc] = '.';
                    }
                    if (mp[nr][nc] == '+') {
                        mp[nr][nc] = 'W';
                    } else {
                        mp[nr][nc] = 'w';
                    }
                    cr = nr;
                    cc = nc;
                    break;
                case 'b': 
                    if (mp[fr][fc] == '.') {
                        mp[fr][fc] = 'b';
                        mp[nr][nc] = 'w';

                        if (mp[cr][cc] == 'W') {
                            mp[cr][cc] = '+';
                        } else {
                            mp[cr][cc] = '.';
                        }
                        cr = nr;
                        cc = nc;
                    }
                    if (mp[fr][fc] == '+') {
                        mp[fr][fc] = 'B';
                        mp[nr][nc] = 'w';
                        if (mp[cr][cc] == 'W') {
                            mp[cr][cc] = '+';
                        } else {
                            mp[cr][cc] = '.';
                        }
                        cr = nr;
                        cc = nc;
                    }
                    break;
                case 'B':
                    if (mp[fr][fc] == '.') {
                        mp[fr][fc] = 'b';
                        mp[nr][nc] = 'W';
                        if (mp[cr][cc] == 'W') {
                            mp[cr][cc] = '+';
                        } else {
                            mp[cr][cc] = '.';
                        }
                        cr = nr;
                        cc = nc;
                    }
                    if (mp[fr][fc] == '+') {
                        mp[fr][fc] = 'B';
                        mp[nr][nc] = 'W';
                        if (mp[cr][cc] == 'W') {
                            mp[cr][cc] = '+';
                        } else {
                            mp[cr][cc] = '.';
                        }
                        cr = nr;
                        cc = nc;
                    }
                    break;
                case '#': case 'w': case 'W':
                    break;
            }

            int flag = 1;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (mp[i][j] == 'b') {
                        flag = 0; break;
                    }
                }
            }
            if (flag) {
                fflag = 0;
                break;
            }
        }

        if (fflag == 0) {
            cout << "Game " << ++t << ": complete\n";
        } else {
            cout << "Game " << ++t << ": incomplete\n";
        }
        for (int i = 0; i < r; i++) {
            cout << mp[i] << '\n';
        }
    }
}