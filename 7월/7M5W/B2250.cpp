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

vector<pair<int,int>> w;
vector<int> p; //for parent check
vector<int> sub; //count number of sub
vector<int> d; //depth
vector<int> pos;
int root, md; //max depth
vector<pair<int, int>> width;

int getSub(int X) {
    if (X == -1) return 0;
    else return sub[X];
}

void dfsCntSub(int X) {
    if (X == root) d[X] = 0;
    else d[X] = d[p[X]] + 1;
    md = max(d[X], md);
    sub[X] = 1;
    if (w[X].first != -2) dfsCntSub(w[X].first), sub[X] += sub[w[X].first];
    if (w[X].second!= -2) dfsCntSub(w[X].second), sub[X] += sub[w[X].second];
}

void dfsGetPos(int X, int from) {
    int left, right;
    left = right = 0;
    if (X == root) pos[X] = 0;
    else {
        if (from == -1) {
            if (w[X].second != -2) right = sub[w[X].second];
            pos[X] = pos[p[X]] - right - 1;
        }
        else if (from == 1){
            if (w[X].first != -2) left = sub[w[X].first];
            pos[X] = pos[p[X]] + left + 1;
        }
    }
    if (width[d[X]].first > pos[X]) width[d[X]].first = pos[X];
    if (width[d[X]].second < pos[X]) width[d[X]].second = pos[X];
    if (w[X].first != -2) dfsGetPos(w[X].first, -1);
    if (w[X].second != -2) dfsGetPos(w[X].second, 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    int i, x, l, r;
    w.resize(N);
    p.resize(N, -1);
    d.resize(N);
    sub.resize(N);
    pos.resize(N);
    for (i = 0; i < N; i++) {
        cin >> x >> l >> r;
        x--, l--, r--;
        w[x] = { l, r };
        if (l != -2) p[l] = x;
        if (r != -2) p[r] = x;
    }
    root = -1, md = 0;
    for (i = 0; i < N; i++) if (p[i] == -1) root = i;
    dfsCntSub(root);
    width.resize(md + 1, { 20000, -20000 });
    dfsGetPos(root, 0);
    int result_depth = -1;
    int result_width = -1;
    for (i = 0; i <= md; i++) {
        if (width[i].second - width[i].first > result_width) {
            result_width = width[i].second - width[i].first;
            result_depth = i;
        }
    }
    cout << result_depth + 1 << ' ' << result_width + 1;
    return 0;
}