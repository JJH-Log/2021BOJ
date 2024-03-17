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

vector<int> v; // for union-find
vector<vector<int>> w;
vector<int> dn;
vector<bool> isCut;
vector<int> result;
int dfsn;

int dfsCut(int now, int parent, bool isRoot) {
    /*============================================
    vector<vector<int>> w : adj graph
    vector<int> dn : check for dfsn (init with 0)
    vector<bool> isCut : check for Articulation Point
    int dfsn : dfs number
    ============================================*/
    int next, child, ans, FLAG;
    dn[now] = ++dfsn;
    FLAG = dn[now];
    child = 0;
    for (int i = 0; i < w[now].size(); i++) {
        next = w[now][i];
        if (parent == next) continue;
        if (dn[next]) FLAG = min(FLAG, dn[next]);
        else {
            child++;
            ans = dfsCut(next, now, false);
            if (!isRoot && dn[now] <= ans) isCut[now] = true;
            FLAG = min(FLAG, ans);
        }
    }
    if (isRoot && child > 1) isCut[now] = true;
    return FLAG;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int i, now, x, y;
    cin >> N >> M;
    dn.resize(N, 0);
    isCut.resize(N, false);
    w.resize(N);
    v.resize(N);
    dfsn = 0;
    for (i = 0; i < N; i++) v[i] = i;
    for (i = 0; i < M; i++) {
        cin >> x >> y;
        w[x - 1].push_back(y - 1);
        w[y - 1].push_back(x - 1);
    }
    for (i = 0; i < N; i++) if (!dn[i]) dfsCut(i, -1, true);
    for (i = 0; i < N; i++) if (isCut[i]) result.push_back(i + 1);
    cout << result.size() << '\n';
    for (auto& r : result) cout << r << ' ';

    return 0;
}