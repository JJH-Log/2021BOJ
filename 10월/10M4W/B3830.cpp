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

struct info{
    int parent, rank;
    lld val;
};

vector<info> v;
int N, M;

pair<int, lld> find(int X, lld diff) {
    if (v[X].parent == X) return { X, diff };
    return find(v[X].parent, diff + v[X].val );
}

void combine(int A, int B, lld w) {
    pair<int, lld> Ap, Bp;
    Ap = find(A, 0);
    Bp = find(B, 0);
    if (v[Ap.first].rank >= v[Bp.first].rank) {
        if (v[Ap.first].rank == v[Bp.first].rank) v[Ap.first].rank++;
        v[Bp.first].parent = Ap.first;
        v[Bp.first].val = Ap.second - Bp.second - w;
    }
    else if (v[Ap.first].rank < v[Bp.first].rank) {
        v[Ap.first].parent = Bp.first;
        v[Ap.first].val = -Ap.second + Bp.second + w;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    pair<int, lld> xp, yp;
    int x, y, w;
    char q;
    while (true) {
        cin >> N >> M;
        if (!N) break;
        v.resize(N);
        for (int i = 0; i < N; i++) v[i] = { i, 0, 0 };

        for (int i = 0; i < M; i++) {
            cin >> q >> x >> y;
            x--, y--;
            if (q == '!') {
                cin >> w;
                combine(x, y, w);
            }
            if (q == '?') {
                xp = find(x, 0);
                yp = find(y, 0);
                if (xp.first == yp.first) cout << xp.second - yp.second << '\n';
                else cout << "UNKNOWN\n";
            }
        }
        v.clear();
    }

    return 0;
}
