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
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

int v[9][3] = { 0, };
int w[3] = { 0, };
int input[3] = { 0, };
map<int, int> m;

bool getFLAG(int pos) {
    int X = (v[w[0]][pos] | v[w[1]][pos] | v[w[2]][pos]);
    return ((X == 1) || (X == 2) || (X == 4) || (X == 7));
}

int concat(int x, int y, int z) {
    return 100 * x + 10 * y + z;
}

void backTracking(int idx, int cnt) { //bound - idx : 9, cnt : 3
    if (cnt == 3) {
        if (getFLAG(0) && getFLAG(1) && getFLAG(2)) {
            int num = concat(w[0] + 1, w[1] + 1, w[2] + 1);
            m[num] = 1;
        }
        return;
    }

    for (int i = idx; i < 9; i++) {
        w[cnt] = i;
        backTracking(i + 1, cnt + 1);
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, M;
    int answer, score, GFLAG;
    string s;
    for (i = 0; i < 9; i++) {
        for (k = 0; k < 3; k++) {
            cin >> s;
            if (s[0] == 'C' || s[0] == 'Y' || s[0] == 'G') v[i][k] = 4;
            if (s[0] == 'T' || s[0] == 'R' || s[0] == 'W') v[i][k] = 2;
            if (s[0] == 'S' || s[0] == 'B') v[i][k] = 1;
        }
    }
    backTracking(0, 0);
    answer = m.size();
    score = 0;
    GFLAG = false;
    cin >> M;
    for (i = 0; i < M; i++) {
        cin >> s;
        if (s == "H") {
            cin >> input[0] >> input[1] >> input[2];
            sort(input, input + 3);
            int now = concat(input[0], input[1], input[2]);
            if (m.count(now) && m[now] == 1) {
                m[now] = 0;
                score++;
                answer--;
            }
            else score--;
        }
        else if (s == "G") {
            if (!answer && !GFLAG) score += 3, GFLAG = true;
            else score--;
        }
    }
    cout << score;
    return 0;
}