#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 1000000
#define BOUND 1000000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

struct pos {
    lld x, y;
};

lld ccw(pos A, pos B, pos C) {
    lld result = A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
    if (result > 0) return 1;
    if (result < 0) return -1;
    return 0;
}

bool isMiddle(pos A, pos B, pos C) {
    return ((A.x - C.x) * (B.x - C.x) <= 0) && ((A.y - C.y) * (B.y - C.y) <= 0);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int posset[4][3] = { {0,1,2}, {0,1,3},{2,3,0},{2,3,1} };
    pos v[4];
    lld result[4];
    bool FLAG = false;
    for (int i = 0; i < 4; i++) cin >> v[i].x >> v[i].y;
    
    if ((ccw(v[0], v[1], v[2]) * ccw(v[0], v[1], v[3]) < 0) && (ccw(v[2], v[3], v[0]) * ccw(v[2], v[3], v[1]) < 0)) FLAG = true;
    for (auto w : posset) {
        if (ccw(v[w[0]], v[w[1]], v[w[2]]) == 0 && isMiddle(v[w[0]], v[w[1]], v[w[2]])) FLAG = true;
    }

    cout << FLAG;

    return 0;
}
