#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;

vector<vector<int>> v;

#define NUM 1000000;

int encrypt(string s) {
    v.resize(s.length(), vector<int>(2, 0));
    int i, token, btoken, result;

    token = -1;
    for (i = 0; i < s.length(); i++) {
        btoken = token;
        token = s[i] - '0';
        if (i == 0) {
            if (token == 0) return 0;
            if ((token == 1) || (token == 2)) v[0][1] = 1;
            v[0][0] = 1;
        }
        else {
            if (token == 0) {
                if ((btoken != 1) && (btoken != 2)) return 0;
                else v[i][0] = v[i - 1][1];
            }
            else {
                if ((btoken == 2) && (token > 6)) { v[i][0] = v[i - 1][0]; }
                else v[i][0] = (v[i - 1][0] + v[i - 1][1]) % NUM;
                if ((token == 1) || (token == 2)) v[i][1] = v[i - 1][0];
            }
        }
    }
    return v[s.length()-1][0];
}

int main() {
    string s;
    cin >> s;
    cout << encrypt(s);
    return 0;
}

