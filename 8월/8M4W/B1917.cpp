#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct info {
    int x, y, d, c;
};

vector<vector<string>> pattern = {
    {"1000", "1111", "1000"},
    {"0100", "1111", "1000"},
    {"0010", "1111", "1000"},
    {"0001", "1111", "1000"},
    {"0100", "1111", "0100"},
    {"0010", "1111", "0100"},
    {"00111", "11100"},
    {"0011", "0110", "1100"},
    {"0011", "1110", "1000"},
    {"1100", "0111", "0100"},
    {"0100", "1110", "0011"}
};
vector<vector<int>> v;

bool isIn(int x, int y) { return x >= 0 && x < 6 && y >= 0 && y < 6; }

bool isMatch(int x, int y, int num) {
    for (int i = 0; i < pattern[num].size(); i++) {
        for (int j = 0; j < pattern[num][i].size(); j++) {
            if (!isIn(x + i, y + j) || (v[x + i][y + j] != pattern[num][i][j] - '0')) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> rotate() {
    vector<vector<int>> w;
    w.resize(6, vector<int>(6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            w[j][5 - i] = v[i][j];
        }
    }
    return w;
}

vector<vector<int>> invert() {
    vector<vector<int>> w;
    w.resize(6, vector<int>(6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            w[i][j] = v[i][5 - j];
        }
    }
    return w;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, k, r, temp;
    info ans;
    for (t = 0; t < 3; t++) {
        v.resize(6, vector<int>(6, 0));
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) cin >> v[i][j];
        }
        bool FLAG = true;
        for (r = 0; r < 8 && FLAG; r++) {
            for (i = 0; i < 6 && FLAG; i++) {
                for (j = 0; j < 6 && FLAG; j++) {
                    for (k = 0; k < pattern.size() && FLAG; k++) {
                        if (isMatch(i, j, k)) FLAG = false;
                    }
                }
            }
            v = rotate();
            if (r == 3) v = invert();
        }
        if (!FLAG) cout << "yes\n";
        else cout << "no\n";
        v.clear();
    }
    
    return 0;
}