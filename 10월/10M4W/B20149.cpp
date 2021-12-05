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

pair<double, double> getMiddle(pos A, pos B, pos C, pos D) {
    double p, q;
    p = q = 0;
    pos d1 = { B.x - A.x, B.y - A.y };
    pos d2 = { D.x - C.x, D.y - C.y };

    if (A.x == B.x) {
        p = A.x;
        q = ((double)d2.y * A.x + D.x * C.y - D.y * C.x) / d2.x;
    }
    else if (C.x == D.x) {
        return getMiddle(C, D, A, B);
    }
    else {
        double dx1 = (double)d1.y / d1.x;
        double dx2 = (double)d2.y / d2.x;
        double k = (((double)C.y - A.y) - dx2 * (C.x - A.x)) / (dx1 - dx2);
        p = (double)A.x + k;
        q = (double)A.y + dx1 * k;
    }
    return { p, q };
}

pos getSamePoint(pos A, pos B, pos C, pos D) {
    if (A.x == C.x && A.y == C.y) return A;
    if (A.x == D.x && A.y == D.y) return A;
    return B;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << fixed;
    cout.precision(13);

    int posset[4][3] = { {0,1,2}, {0,1,3},{2,3,0},{2,3,1} };
    pos v[4];
    lld result[4];
    int FLAG = -1;
    for (int i = 0; i < 4; i++) cin >> v[i].x >> v[i].y;
    
    if ((ccw(v[0], v[1], v[2]) * ccw(v[0], v[1], v[3]) < 0) && (ccw(v[2], v[3], v[0]) * ccw(v[2], v[3], v[1]) < 0)) FLAG = 9;
    int cnt = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for (auto w : posset) {
        if (ccw(v[w[0]], v[w[1]], v[w[2]]) == 0) {
            if(isMiddle(v[w[0]], v[w[1]], v[w[2]])) FLAG = cnt, cnt2++;
            cnt3++;
        }
        cnt++;
    }
    if (FLAG == -1) cout << 0;
    else if (FLAG == 9) {
        cout << "1\n" << getMiddle(v[0], v[1], v[2], v[3]).first << ' ' << getMiddle(v[0], v[1], v[2], v[3]).second;
    }
    else {
        if (cnt2 == 1) {
            for (auto w : posset) {
                if (ccw(v[w[0]], v[w[1]], v[w[2]]) == 0 && isMiddle(v[w[0]], v[w[1]], v[w[2]])) cout << "1\n" << v[w[2]].x << ' ' << v[w[2]].y;
            }
        }
        else if (cnt2 == 2 && cnt3 != 4) {
            pos same = getSamePoint(v[0], v[1], v[2], v[3]);
            cout << "1\n" << same.x << ' ' << same.y;
        }
        else {
            int key = -1;
            cout << "1\n";
            if (v[0].x == v[2].x && v[0].y == v[2].y && isMiddle(v[1], v[3], v[0])) cout << v[0].x << ' ' << v[0].y;
            else if (v[0].x == v[3].x && v[0].y == v[3].y && isMiddle(v[1], v[2], v[0])) cout << v[0].x << ' ' << v[0].y;
            else if (v[1].x == v[2].x && v[1].y == v[2].y && isMiddle(v[0], v[3], v[1])) cout << v[1].x << ' ' << v[1].y;
            else if (v[1].x == v[3].x && v[1].y == v[3].y && isMiddle(v[0], v[2], v[1])) cout << v[1].x << ' ' << v[1].y;
        }

    }

    return 0;
}
